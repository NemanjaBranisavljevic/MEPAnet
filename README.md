# EPANET API for MATLAB

## Overview

The EPANET API for MATLAB provides a set of functions to interface with the EPANET hydraulic modeling software. This allows users to run simulations, manipulate network data, and analyze results directly within the MATLAB environment.

## Table of Contents

- [Installation](#installation)
- [Getting Started](#getting-started)
- [API Functions](#api-functions)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Installation

To use the EPANET API in MATLAB, follow these steps:

1. **Download EPANET DLL**: Ensure you have the latest version of EPANET.
2. **Add EPANET DLLs**: Place the EPANET DLL files in a directory accessible by MATLAB.

## Getting Started

To begin using the EPANET API:

1. Initialize the EPANET engine:
   ```matlab
   ENopen('path/to/your/network.inp', 'output.rpt');
   ```

2. Load the network data:
   ```matlab
   ENread;
   ```

3. Run the simulation:
   ```matlab
   ENsolveH;  % Hydraulic analysis
   ENsolveQ;  % Quality analysis
   ```

4. Retrieve results:
   ```matlab
   [nodeHead, nodeQuality] = ENgetNodeResults;
   ```

5. Close the EPANET engine:
   ```matlab
   ENclose;
   ```

## API Functions

| Function                      | Description                                      |
|-------------------------------|--------------------------------------------------|
| `ENopen(filename, rptFile)`   | Opens an EPANET project file and report file.   |
| `ENclose()`                   | Closes the EPANET engine.                        |
| `ENread()`                    | Reads network data from the EPANET project file.|
| `ENsolveH()`                  | Solves the hydraulic equations.                  |
| `ENsolveQ()`                  | Solves the water quality equations.              |
| `ENgetNodeResults()`          | Retrieves hydraulic and quality results for nodes.|

## Examples

### Example 1: Basic Network Simulation

```matlab
% Initialize EPANET
ENopen('example_network.inp', 'output.rpt');

% Read network data
ENread;

% Solve for hydraulics
ENsolveH;

% Get results
[nodeHead, nodeQuality] = ENgetNodeResults;

% Close EPANET
ENclose;

% Display results
disp(nodeHead);
disp(nodeQuality);
```

### Example 2: Modify Network Parameters

```matlab
% Initialize EPANET
ENopen('example_network.inp', 'output.rpt');

% Read network data
ENread;

% Set a new demand for a node
ENsetNodeDemand(1, 150);  % Set demand for node 1 to 150 L/s

% Solve for hydraulics
ENsolveH;

% Close EPANET
ENclose;
```

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any enhancements or bug fixes.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Contact

For questions or feedback, please contact:

- **Name**: Nemanja Branisavljevic
- **Email**: nbranisavljevic@yahoo.com
- **GitHub**: [My profile](https://github.com/NemanjaBranisavljevic)
```
