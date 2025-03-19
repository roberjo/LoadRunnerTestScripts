#ifndef _COMMON_FUNCTIONS_H
#define _COMMON_FUNCTIONS_H

#include "lrun.h"
#include "web_api.h"
#include "OktaAuthentication.h"

// Application URLs
char *base_url = "http://your-react-app-url";  // Replace with actual application URL
char *api_base_url = "http://your-api-base-url";  // Replace with actual API base URL

// Function to generate random string
void generate_random_string(char *str, size_t size) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = lr_rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
}

// Function to generate random data for trade plan
void generate_trade_plan_data() {
    char random_suffix[7];
    char first_names[][20] = {"John", "Mary", "Robert", "Patricia", "Michael", "Jennifer"};
    char last_names[][20] = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Miller"};
    char securities[][30] = {"AAPL", "MSFT", "GOOGL", "AMZN", "TSLA", "BRK.A"};
    char currencies[][10] = {"dollars", "shares"};
    char frequencies[][10] = {"daily", "monthly", "quarterly"};
    int random_amount;
    
    // Generate random suffix
    generate_random_string(random_suffix, 6);
    
    // Set portfolio manager (random name)
    lr_save_string(first_names[lr_rand() % 6], "portfolio_manager_first");
    lr_save_string(last_names[lr_rand() % 6], "portfolio_manager_last");
    
    // Set client name (random name with unique suffix)
    lr_save_string(first_names[lr_rand() % 6], "client_first_name");
    lr_save_string(last_names[lr_rand() % 6], "client_last_name");
    lr_save_string(random_suffix, "client_suffix");
    
    // Generate account number (random 8-digit number)
    lr_save_int(10000000 + (lr_rand() % 90000000), "account_number");
    
    // Set trade plan dates
    lr_save_datetime("%Y-%m-%d", DATE_NOW, "start_date");
    lr_save_datetime("%Y-%m-%d", DATE_NOW + (86400 * 90), "end_date");  // 90 days from now
    
    // Set security name
    lr_save_string(securities[lr_rand() % 6], "security_name");
    
    // Set currency type (dollars or shares)
    lr_save_string(currencies[lr_rand() % 2], "currency_type");
    
    // Set amount (random between 1000 and 100000)
    random_amount = 1000 + (lr_rand() % 99000);
    lr_save_int(random_amount, "trade_amount");
    
    // Set frequency
    lr_save_string(frequencies[lr_rand() % 3], "trade_frequency");
}

// Function to handle React app initial load
int load_react_app() {
    int rc;
    
    lr_start_transaction("T01_LoadReactApp");
    
    rc = web_url("React_App_Home", 
        "URL={base_url}",
        "Resource=0",
        "RecContentType=text/html",
        "Referer=",
        "Snapshot=t1.inf",
        "Mode=HTML",
        LAST);
    
    // Wait for React app to fully load
    lr_think_time(3);
    
    lr_end_transaction("T01_LoadReactApp", LR_AUTO);
    
    return rc;
}

// Function to wait for AJAX requests to complete
int wait_for_ajax_completion() {
    lr_think_time(1);
    return LR_PASS;
}

#endif // _COMMON_FUNCTIONS_H
