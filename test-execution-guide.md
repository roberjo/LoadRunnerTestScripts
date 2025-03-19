# LoadRunner Test Execution Guide for React UI and API Testing

## Prerequisites

1. LoadRunner 2022 VuGen installed
2. Okta client credentials (client ID and client secret)
3. Access to target application and API endpoints

## Project Setup

1. Create a new LoadRunner VuGen project
2. Import the following scripts:
   - Common/OktaAuthentication.h
   - Common/CommonFunctions.h
   - UI_AssociateSearch.usr
   - UI_CreateTradePlan.usr
   - API_PlanEndpoint.usr
   - API_AssociateSearch.usr
   - API_Email.usr

## Configuration Steps

1. **Update Application URLs**:
   - Open `CommonFunctions.h`
   - Update `base_url` with your React application URL
   - Update `api_base_url` with your API base URL

2. **Configure Okta Authentication**:
   - Open `OktaAuthentication.h`
   - Update `okta_token_endpoint` with your Okta token endpoint URL
   - Replace `{CLIENT_ID}` with your actual client ID
   - Replace `{CLIENT_SECRET}` with your actual client secret
   - Update `auth_scope` if necessary

3. **Adjust UI Selectors** (if needed):
   - Review the web_js_run commands in UI scripts
   - Update CSS selectors to match your React app's actual DOM structure

## Running the Tests

### Option 1: Individual Scripts

1. Open LoadRunner VuGen
2. Open each script individually
3. Click "Run" to execute and validate each script

### Option 2: Scenario-based Load Testing

1. Open LoadRunner Controller
2. Import the scenario files:
   - UI_Test_Scenario.lrs
   - API_Test_Scenario.lrs
3. Configure load generators and monitoring
4. Run the scenarios

## Monitoring and Analysis

1. **Key Metrics to Monitor**:
   - Average response time per transaction
   - Error rate
   - Throughput (requests per second)
   - UI rendering time

2. **Analysis Reports**:
   - Transaction Summary Report
   - Error Analysis Report
   - UI Performance Report

## Test Parameters to Consider

1. **Ramp-up Strategy**:
   - Start with 5-10 virtual users
   - Gradually increase to 100 concurrent users
   - Monitor system response during ramp-up

2. **Test Duration**:
   - UI tests: 20 minutes
   - API tests: 15 minutes
   - Adjust as needed based on test objectives

3. **Think Time**:
   - UI scripts: 0.5 seconds (default)
   - API scripts: 0.1 seconds (default)
   - Adjust to simulate realistic user behavior

## Troubleshooting

1. **Authentication Issues**:
   - Verify Okta credentials
   - Check token endpoint URL
   - Ensure proper scopes are set

2. **UI Interaction Failures**:
   - Review browser console logs
   - Update CSS selectors to match current DOM structure
   - Increase wait times for AJAX operations

3. **API Response Errors**:
   - Check API endpoint URLs
   - Verify request payloads
   - Ensure proper headers are set
