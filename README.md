# LoadRunner Test Scripts

![LoadRunner](https://upload.wikimedia.org/wikipedia/en/6/61/HPE_LoadRunner_logo.png)

## Overview
Welcome to the **LoadRunnerTestScripts** repository! This collection of scripts is designed to assist performance testers and engineers in automating load testing using **Micro Focus LoadRunner**. The scripts cover a variety of use cases, including web applications, APIs, and database performance testing.

## Features
- Pre-configured **VuGen** scripts for different protocols.
- Parameterization and correlation examples.
- Best practices for **LoadRunner** scripting.
- Sample test scenarios for various workloads.
- Reusable functions to enhance script modularity.

## Getting Started
### Prerequisites
Before using these scripts, ensure you have the following:
- **Micro Focus LoadRunner** installed (Community or Enterprise Edition)
- Basic knowledge of LoadRunner **VuGen**
- Access to the target application or API under test

### Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/roberjo/LoadRunnerTestScripts.git
   ```
2. Open **LoadRunner VuGen** and load the script you want to use.
3. Configure runtime settings as needed.
4. Execute the script to validate functionality.

## Repository Structure
```
LoadRunnerTestScripts/src
├── WebScripts          # Scripts for web applications
├── APIScripts          # Scripts for API testing (REST/SOAP)
├── DatabaseScripts    # Scripts for database load testing
├── Utilities          # Reusable functions and helper files
└── README.md           # Documentation
```

## Usage Guidelines
- Modify the **parameters** in the scripts to match your test environment.
- Use **correlation** techniques to handle dynamic session data.
- Optimize **think times** and pacing to mimic real user behavior.
- Always validate script execution in VuGen before running large-scale tests.

## Contributing
Contributions are welcome! If you have new test scripts or improvements, feel free to:
1. Fork the repository.
2. Create a new branch.
3. Commit your changes.
4. Submit a pull request.

## License
This project is licensed under the **MIT License**. See [LICENSE](LICENSE) for details.

## Contact
For any queries or support, please reach out via the **Issues** section or contact the repository maintainer.

Happy Load Testing! 🚀

