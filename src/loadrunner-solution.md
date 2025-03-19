# LoadRunner VUGen Solution for React UI and API Testing

## Solution Architecture

The load testing solution consists of two main components:

1. **Web UI Scripts** - For simulating user interactions with the React frontend
2. **API Scripts** - For direct testing of backend APIs with JWT authentication

### Test Scenarios

1. **Associate Search Flow**
   - Navigate to search page
   - Enter first and last name
   - Submit search
   - Verify results

2. **New Trade Plan Flow**
   - Navigate to trade plans page
   - Click "New Trade Plan" button
   - Fill out trade plan form with required fields
   - Submit form
   - Verify plan creation

3. **Direct API Testing**
   - Authenticate with Okta
   - Test `/v1/api/itr/plan` (GET/POST)
   - Test `/v1/api/associatesearch` (GET)
   - Test `/v1/api/email` (POST)

## Implementation Plan

### 1. LoadRunner Scripts Organization

```
LoadRunner Project/
├── Scripts/
│   ├── UI_AssociateSearch.usr
│   ├── UI_CreateTradePlan.usr
│   ├── API_PlanEndpoint.usr
│   ├── API_AssociateSearch.usr
│   ├── API_Email.usr
│   └── Common/
│       ├── OktaAuthentication.h
│       └── CommonFunctions.h
├── Scenarios/
│   ├── UI_Test_Scenario.lrs
│   └── API_Test_Scenario.lrs
└── Results/
```

### 2. Common Functions and Libraries

Create reusable components that will be used across scripts.
