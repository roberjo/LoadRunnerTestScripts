#ifndef _OKTA_AUTHENTICATION_H
#define _OKTA_AUTHENTICATION_H

#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"

// Okta Authentication parameters
char *okta_token_endpoint = "https://your-okta-domain/oauth2/default/v1/token";
char *client_id = "{CLIENT_ID}";  // Replace with actual client ID
char *client_secret = "{CLIENT_SECRET}";  // Replace with actual client secret
char *auth_scope = "api://default";

// Global token variables
char g_access_token[1024] = "";
long g_token_expiry = 0;

// Function to obtain Okta access token using client credentials flow
int obtain_okta_token() {
    int rc;
    char *response_body = NULL;
    long response_size = 0;
    char token_request_body[1024];
    char current_time_str[128];
    long current_time;
    
    // Check if we have a valid token
    time(&current_time);
    if (strlen(g_access_token) > 0 && g_token_expiry > current_time + 60) {
        lr_output_message("Using existing token, valid for %d more seconds", g_token_expiry - current_time);
        return LR_PASS;
    }
    
    // Create request body
    sprintf(token_request_body, "grant_type=client_credentials&scope=%s&client_id=%s&client_secret=%s", 
            auth_scope, client_id, client_secret);
    
    // Set headers
    web_add_header("Content-Type", "application/x-www-form-urlencoded");
    
    lr_start_transaction("Okta_GetAccessToken");
    
    rc = web_custom_request("OktaAccessToken",
        "URL={okta_token_endpoint}",
        "Method=POST",
        "RecContentType=application/json",
        "Body={token_request_body}",
        LAST);
    
    if (rc == LR_PASS) {
        // Extract access token
        rc = web_reg_save_param_json("ParamName=access_token", 
                                     "QueryString=$.access_token",
                                     "NotFound=Error",
                                     LAST);
        
        // Extract expiry (if available)
        rc = web_reg_save_param_json("ParamName=expires_in", 
                                     "QueryString=$.expires_in",
                                     "NotFound=Warning",
                                     LAST);
        
        if (rc == LR_PASS) {
            // Save token to global variable
            strcpy(g_access_token, lr_eval_string("{access_token}"));
            
            // Calculate expiry time
            time(&current_time);
            g_token_expiry = current_time + atol(lr_eval_string("{expires_in}"));
            
            lr_output_message("Successfully obtained Okta access token, valid until %s", 
                               ctime(&g_token_expiry));
        } else {
            lr_error_message("Failed to extract access token from response");
            lr_end_transaction("Okta_GetAccessToken", LR_FAIL);
            return LR_FAIL;
        }
    } else {
        lr_error_message("Failed to obtain Okta access token");
        lr_end_transaction("Okta_GetAccessToken", LR_FAIL);
        return LR_FAIL;
    }
    
    lr_end_transaction("Okta_GetAccessToken", LR_PASS);
    return LR_PASS;
}

// Function to add authorization header with access token
int add_auth_header() {
    char auth_header[1100];
    
    // Ensure we have a valid token
    if (obtain_okta_token() != LR_PASS) {
        return LR_FAIL;
    }
    
    // Add authorization header
    sprintf(auth_header, "Bearer %s", g_access_token);
    web_add_header("Authorization", auth_header);
    
    return LR_PASS;
}

#endif // _OKTA_AUTHENTICATION_H
