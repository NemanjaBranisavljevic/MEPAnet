

#include <stdlib.h>
#include "mex.h" // will #include <stdio.h>
#include "MEpanet.h"

#if FunENopen

// Funkcija EpaNet-a int ENopen(char* f1, char* f2,char* f3); otvara i cita .inp file (file koji sadrzi podatke o mrezi)
//  i kreira .rtp file (file koji nam daje izvestaj) i .bin file (binarni izvestaj - opciono)
////////////////////////////////////////////////////////////////////////////////////////////
// Arguments:
//
// f1:	name of an EPANET Input file
// f2:	name of an output Report file
// f3:	name of an optional binary Output file.
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
// If there is no need to save EPANET's binary Output file then f3 can be an empty string ("").
//
// If f2 is an empty string, then reporting will be made to the operating system's stdout device (which is usually the console).
///////////////////////////////////////////////////////////////////////////////////////////////
//
// Funkcija se poziva sa: [error] = ENopen('c:/ime direktorijuma/ime fajla.inp','c:/ime direktorijuma/ime fajla.rpt','c:/ime direktorijuma/ime fajla.bin')
//
////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	char *input1, *input2, *input3;
	int input1_len, status1, input2_len, status2, input3_len, status3;

	double *temp;
	int error;

	if (nrhs == 3)
	{

		// Check for proper number of arguments
		if (nrhs == 0)
		{
			mexPrintf("Sintaksa: ENopen('c:/ime direktorijuma/ime fajla.inp','c:/ime direktorijuma/ime fajla.rpt','c:/ime direktorijuma/ime fajla.bin')\r\n");
			return;
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Provera raznih osobina unosa za input1
		//  First input must be a string
		if (mxIsChar(prhs[0]) != 1)
		{
			mexPrintf("Prvi argument u pozivu funkcije mora biti string sa imenom putanje do .inp file-a.\r\n");
			return;
		}
		// Input must be a row vector
		if (mxGetM(prhs[0]) != 1)
		{
			mexPrintf("Prvi argument mora biti 1D char array.\r\n");
			return;
		}

		// Get the length of the input string
		input1_len = (mxGetM(prhs[0]) * mxGetN(prhs[0])) + 1;
		// Allocate memory for input  string
		input1 = (char *)mxCalloc(input1_len, sizeof(char));
		// Copy the string data from prhs[0] into a C string
		// input_ buf.
		// If the string array contains several rows, they are copied,
		// one column at a time, into one long string array.
		//
		status1 = mxGetString(prhs[0], input1, input1_len);
		if (status1 != 0)
		{
			mexPrintf("Nema dovoljno mesta u stringu. Verovatno je pogresno ime adrese\r\n");
			mexPrintf("Prvi argument mora biti 1D char array.\r\n");
			return;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Provera raznih osobina unosa za input2
		//  First input must be a string
		if (mxIsChar(prhs[1]) != 1)
		{
			mexPrintf("Drugi argument u pozivu funkcije mora biti string sa imenom putanje do .inp file-a.\r\n");
			return;
		}
		// Input must be a row vector
		if (mxGetM(prhs[1]) != 1)
		{
			mexPrintf("Drugi argument mora biti 1D char array.\r\n");
			return;
		}

		// Get the length of the input string
		input2_len = (mxGetM(prhs[1]) * mxGetN(prhs[1])) + 1;
		// Allocate memory for input  string
		input2 = (char *)mxCalloc(input2_len, sizeof(char));
		// Copy the string data from prhs[0] into a C string
		// input_ buf.
		// If the string array contains several rows, they are copied,
		// one column at a time, into one long string array.
		//
		status2 = mxGetString(prhs[1], input2, input2_len);
		if (status2 != 0)
		{
			mexPrintf("Nema dovoljno mesta u stringu. Verovatno je pogresno ime adrese\r\n");
			mexPrintf("Drugi argument mora biti 1D char array.\r\n");
			return;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Provera raznih osobina unosa za input3
		//  First input must be a string
		if (mxIsChar(prhs[2]) != 1)
		{
			mexPrintf("Treci argument u pozivu funkcije mora biti string sa imenom putanje do .inp file-a.\r\n");
			return;
		}
		// Input must be a row vector
		if (mxGetM(prhs[2]) != 1)
		{
			mexPrintf("Treci argument mora biti 1D char array.\r\n");
			return;
		}

		// Get the length of the input string
		input3_len = (mxGetM(prhs[2]) * mxGetN(prhs[2])) + 1;
		// Allocate memory for input  string
		input3 = (char *)mxCalloc(input3_len, sizeof(char));
		// Copy the string data from prhs[0] into a C string
		// input_ buf.
		// If the string array contains several rows, they are copied,
		// one column at a time, into one long string array.
		//
		status3 = mxGetString(prhs[2], input3, input3_len);
		if (status3 != 0)
		{
			mexPrintf("Nema dovoljno mesta u stringu. Verovatno je pogresno ime adrese\r\n");
			mexPrintf("Treci argument mora biti 1D char array.\r\n");
			return;
		}
	}

	error = ENopen(input1, input2, input3);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = error;
	mxFree(input1);
	mxFree(input2);
	mxFree(input3);
}

#endif

#if FunENclose

/////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENclose( void )
// Description:
//
//
// Closes down the Toolkit system (including all files being processed).
//
// Returns:
//
//
// Returns an error code.
//
// Notes:
//
//
// ENclose must be called when all processing has been completed,
// even if an error condition was encountered.
////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u: [error]=ENclose
//
//////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	double *temp;
	int error;

	error = ENclose();

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = error;
}

#endif

#if FunENgetnodeindex

//////////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENgetnodeindex( char* id, int* index )
// Description:
//
// Retrieves the index of a node with a specified ID.
//
// Arguments:
//
// id:	node ID label
// index:	node index
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
// Node indexes are consecutive integers starting from 1.
////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u: [node_index]=ENgetnodeindex('node_ID_label')
//
//////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	int nodeindex;
	char *node_ID_label;
	int node_ID_label_len, status;

	double *temp;
	int error;

	// Check for proper number of arguments
	if (nrhs == 0)
	{
		mexPrintf("Sintaksa: error=ENgetnodeindex('node_ID_label')\r\n");
		return;
	}

	// Provera raznih osobina unosa za node_ID_label
	//  First input must be a string
	if (mxIsChar(prhs[0]) != 1)
	{
		mexPrintf("Prvi argument u pozivu funkcije mora biti string sa imenom (label) cvora.\r\n");
		return;
	}
	// Input must be a row vector
	if (mxGetM(prhs[0]) != 1)
	{
		mexPrintf("Argument mora biti 1D char array.\r\n");
		return;
	}

	// Get the length of the input string
	node_ID_label_len = (mxGetM(prhs[0]) * mxGetN(prhs[0])) + 1;
	// Allocate memory for input  string
	node_ID_label = (char *)mxCalloc(node_ID_label_len, sizeof(char));
	// Copy the string data from prhs[0] into a C string
	// input_ buf.
	// If the string array contains several rows, they are copied,
	// one column at a time, into one long string array.
	//
	status = mxGetString(prhs[0], node_ID_label, node_ID_label_len);
	if (status != 0)
	{
		mexPrintf("Nema dovoljno mesta u stringu. Verovatno je pogresno ime cvora.\r\n");
		mexPrintf("Argument mora biti 1D char array.\r\n");
		return;
	}

	// Funkcija vraca matricu sa nodeindex u prvoj koloni i kodom greske u drugoj!!

	error = ENgetnodeindex(node_ID_label, &nodeindex);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = nodeindex;

	mxFree(node_ID_label);
}

#endif

#if FunENgetnodeid

//////////////////////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENgetnodeid( int index, char* id )
// Description:
//
// Retrieves the ID label of a node with a specified index.
//
// Arguments:
//
// index:	node index
// id:	ID label of node
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
// The ID label string should be sized to hold at least 15 characters.
//
// Node indexes are consecutive integers starting from 1.
/////////////////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u:   [nodeid]=ENgetnodeid(nodeindex)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	char *nodeid, *name;
	int nodeindex;

	double *temp;
	int error;

	if (nrhs == 1)
	{

		temp = mxGetPr(prhs[0]);
		nodeindex = (int)(temp[0]);
	}

	nodeid = (char *)calloc(5, sizeof(char));

	error = ENgetnodeid(nodeindex, nodeid);

	name = mxCalloc(strlen(nodeid) + 1, sizeof(char));

	strcpy(name, nodeid);
	plhs[0] = mxCreateString(name);

	mxFree(name);

	free(nodeid);
}

#endif

#if FunENgetnodetype

//////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENgetnodetype( int index, int* typecode )
//
// Description:
//
// Retrieves the node-type code for a specific node.
//
// Arguments:
//
// index:	node index
// typecode:	node-type code (see below)
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
// Node indexes are consecutive integers starting from 1.
//
// Node type codes consist of the following constants:
//
// EN_JUNCTION	0	Junction node
// EN_RESERVOIR	1	Reservoir node
// EN_TANK		2	Tank node
////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u:   [nodetype]=ENgetnodetype(nodeindex)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	int nodeindex, nodetype;

	double *temp;
	int error;

	if (nrhs == 1)
	{

		temp = mxGetPr(prhs[0]);
		nodeindex = (int)(temp[0]);
	}

	error = ENgetnodetype(nodeindex, &nodetype);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = nodetype;
}

#endif

#if FunENgetnodevalue

////////////////////////////////////////////////////////////////////////////////////
// Declaration:
//
//		int  ENgetnodevalue( int index, int paramcode, float* value )
//
// Description:
//
// Retrieves the value of a specific link parameter.
//
//
// Arguments:
//
// index:	node index
// paramcode:	parameter code (see below)
// value:	parameter value
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
// Node indexes are consecutive integers starting from 1.
//
// Node parameter codes consist of the following constants:
//
// EN_ELEVATION	0	Elevation
// EN_BASEDEMAND	1	Base demand
// EN_PATTERN	2	Demand pattern index
// EN_EMITTER	3	Emitter coeff.
// EN_INITQUAL	4	Initial quality
// EN_SOURCEQUAL	5	Source quality
// EN_SOURCEPAT	6	Source pattern index
// EN_SOURCETYPE	7	Source type(See note below)
// EN_TANKLEVEL	8	Initial water level in tank
// EN_DEMAND		9	Actual demand
// EN_HEAD		10	Hydraulic head
// EN_PRESSURE	11	Pressure
// EN_QUALITY	12	Actual quality
// EN_SOURCEMASS	13	Mass flow rate per minute of a chemical source
// Parameters	9 - 13 (EN_DEMAND through EN_SOURCEMASS) are computed values. The others are input design parameters.
//
// Source types are identified with the following constants:
//
// EN_CONCEN		0
// EN_MASS		1
// EN_SETPOINT	2
// EN_FLOWPACED	3
// See [SOURCES] for a description of these source types.
//
//
// Values are returned in units which depend on the units used for flow rate in the EPANET input file (see Units of Measurement).
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u:   [nodevalue]=ENgetnodevalue(nodeindex,paramcode);
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	int nodeindex, paramcode;
	float value;

	double *temp;
	int error;

	if (nrhs == 2)
	{

		temp = mxGetPr(prhs[0]);
		nodeindex = (int)(temp[0]);
		temp = mxGetPr(prhs[1]);
		paramcode = (int)(temp[0]);
	}

	error = ENgetnodevalue(nodeindex, paramcode, &value);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = value;
}

#endif

#if FunENgetlinkindex

//////////////////////////////////////////////////////////////////////////////////
// Declaration:
//
//      int  ENgetlinkindex( char* id, int* index )
//
// Description:
//
// Retrieves the index of a link with a specified ID.
//
// Arguments:
//
// id:	link ID label
// index:	link index
// Returns:
//
// Returns an error code.
//
// Notes:
//
// Link indexes are consecutive integers starting from 1.
///////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u: [link_index]=ENgetlinkindex('link_ID_label')
//
//////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	int linkindex;
	char *link_ID_label;
	int link_ID_label_len, status;

	double *temp;
	int error;

	if (nrhs == 1)
	{

		// Check for proper number of arguments
		if (nrhs == 0)
		{
			mexPrintf("Sintaksa: error=ENgetlinkindex('link_ID_label')\r\n");
			return;
		}

		// Provera raznih osobina unosa za node_ID_label
		//  First input must be a string
		if (mxIsChar(prhs[0]) != 1)
		{
			mexPrintf("Prvi argument u pozivu funkcije mora biti string sa imenom (label) cevi.\r\n");
			return;
		}
		// Input must be a row vector
		if (mxGetM(prhs[0]) != 1)
		{
			mexPrintf("Argument mora biti 1D char array.\r\n");
			return;
		}

		// Get the length of the input string
		link_ID_label_len = (mxGetM(prhs[0]) * mxGetN(prhs[0])) + 1;
		// Allocate memory for input  string
		link_ID_label = (char *)mxCalloc(link_ID_label_len, sizeof(char));
		// Copy the string data from prhs[0] into a C string
		// input_ buf.
		// If the string array contains several rows, they are copied,
		// one column at a time, into one long string array.
		//
		status = mxGetString(prhs[0], link_ID_label, link_ID_label_len);
		if (status != 0)
		{
			mexPrintf("Nema dovoljno mesta u stringu. Verovatno je pogresno ime cevi\r\n");
			mexPrintf("Argument mora biti 1D char array.\r\n");
			return;
		}
	}

	// Funkcija vraca matricu sa nodeindex u prvoj koloni i kodom greske u drugoj!!
	error = ENgetlinkindex(link_ID_label, &linkindex);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = linkindex;

	mxFree(link_ID_label);
}

#endif

#if FunENgetlinknodes

//////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENgetlinknodes( int index, int* fromnode, int* tonode )
//
// Description:
//
//
// Retrieves the indexes of the end nodes of a specified link.
//
// Arguments:
//
// index:	link index
// fromnode:	index of node at start of link
// tonode:		index of node at end of link
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
// Node and link indexes are consecutive integers starting from 1.
//
// The From and To nodes are as defined for the link in the EPANET input file. The actual direction of flow in the link is not considered.
//
//
////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u:   [fromnode,tonode]=ENgetlinknodes(linkindex)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	int linkindex, fromnode, tonode;

	double *temp;
	int error;

	if (nrhs == 1)
	{

		temp = mxGetPr(prhs[0]);
		linkindex = (int)(temp[0]);
	}

	error = ENgetlinknodes(linkindex, &fromnode, &tonode);

	plhs[0] = mxCreateDoubleMatrix(1, 2, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = fromnode;
	temp = mxGetPr(plhs[1]);
	*temp = tonode;
}

#endif

#if FunENgetlinktype

//////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENgetlinktype( int index, int* typecode )
//
// Description:
//
// Retrieves the link-type code for a specific link.
//
// Arguments:
//
//
// index:	link index
// typecode:	link-type code (see below)
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
// Link indexes are consecutive integers starting from 1.
//
// Link type codes consist of the following constants:
//
// EN_CVPIPE	0	Pipe with Check Valve
// EN_PIPE	1	Pipe
// EN_PUMP	2	Pump
// EN_PRV	3	Pressure Reducing Valve
// EN_PSV	4	Pressure Sustaining Valve
// EN_PBV	5	Pressure Breaker Valve
// EN_FCV	6	Flow Control Valve
// EN_TCV	7	Throttle Control Valve
// EN_GPV	8	General Purpose Valve
////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u:   [linktype]=ENgetlinktype(linkindex)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	int linkindex, linktype;

	double *temp;
	int error;

	if (nrhs == 1)
	{

		temp = mxGetPr(prhs[0]);
		linkindex = (int)(temp[0]);
	}

	error = ENgetlinktype(linkindex, &linktype);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = linktype;
}

#endif

#if FunENgetlinkid

//////////////////////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENgetlinkid( int index, char* id )
//
// Description:
//
// Retrieves the ID label of a link with a specified index.
//
//
// Arguments:
//
// index:	link index
// id:	ID label of link
//
// Returns:
//
//
// Returns an error code.
//
//
// Notes:
//
//
// The ID label string should be sized to hold at least 15 characters.
//
// Link indexes are consecutive integers starting from 1.
//
/////////////////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u:   [linkid]=ENgetlinkid(linkindex)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	char *linkid, *name;
	int linkindex;

	double *temp;
	int error;

	if (nrhs == 1)
	{

		temp = mxGetPr(prhs[0]);
		linkindex = (int)(temp[0]);
	}

	linkid = (char *)calloc(5, sizeof(char));

	error = ENgetlinkid(linkindex, linkid);

	name = mxCalloc(strlen(linkid) + 1, sizeof(char));

	strcpy(name, linkid);
	plhs[0] = mxCreateString(name);

	mxFree(name);

	free(linkid);
}

#endif

#if FunENgetlinkvalue

////////////////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENgetlinkvalue( int index, int paramcode, float* value )
//
// Description:
//
// Retrieves the value of a specific link parameter.
//
// Arguments:
//
//
// index:	link index
// paramcode:	parameter code (see below)
// value:	parameter value
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
//
// Link indexes are consecutive integers starting from 1.
//
// Link parameter codes consist of the following constants:
//
// EN_DIAMETER		0	Diameter
// EN_LENGTH			1	Length
// EN_ROUGHNESS		2	Roughness coeff.
// EN_MINORLOSS		3	Minor loss coeff.
// EN_INITSTATUS		4	Initial link status (0 = closed, 1 = open)
// EN_INITSETTING	5	Initial pipe roughnessInitial pump speedInitial valve setting
// EN_KBULK			6	Bulk reaction coeff.
// EN_KWALL			7	Wall reaction coeff.
// EN_FLOW			8	Flow rate
// EN_VELOCITY		9	Flow velocity
// EN_HEADLOSS		10	Head loss
// EN_STATUS			11	Actual link status(0 = closed, 1 = open)
// EN_SETTING		12	Pipe roughnessActual pump speedActual valve setting
// EN_ENERGY			13	Energy expended in kwatts
// Parameters		8 - 13 (EN_FLOW through EN_ENERGY) are computed values. The others are design parameters.
//
// Flow rate is positive if the direction of flow is from the designated start node of the link to its designated end node, and negative otherwise.
//
// Values are returned in units which depend on the units used for flow rate in the EPANET input file (see Units of Measurement).
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u:   [linkvalue]=ENgetlinkvalue(linkindex,paramcode);
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	int linkindex, paramcode;
	float linkvalue;

	double *temp;
	int error;

	if (nrhs == 2)
	{

		temp = mxGetPr(prhs[0]);
		linkindex = (int)(temp[0]);
		temp = mxGetPr(prhs[1]);
		paramcode = (int)(temp[0]);
	}

	error = ENgetlinkvalue(linkindex, paramcode, &linkvalue);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = linkvalue;
}

#endif

#if FunENgetcount

////////////////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENgetcount( int countcode, int *count )
//
// Description:
//
// Retrieves the number of network components of a specified type.
//
//
// Arguments:
//
// countcode:	component code (see below)
// count:	number of countcode components in the network
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
//
// Component codes consist of the following:
//
// EN_NODECOUNT		0 	Nodes
// EN_TANKCOUNT		1 	Reservoirs and tank nodes
// EN_LINKCOUNT		2	Links
// EN_PATCOUNT		3	Time patterns
// EN_CURVECOUNT		4	Curves
// EN_CONTROLCOUNT	5	Simple controls
// The number of junctions in a network equals the number of nodes minus the number of tanks and reservoirs.
//
// There is no facility within the Toolkit to add to or delete from the components described in the Input file.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u:   [count]=ENgetcount(countcode);
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	int count, countcode;

	double *temp;
	int error;

	if (nrhs == 1)
	{

		temp = mxGetPr(prhs[0]);
		countcode = (int)(temp[0]);
	}

	error = ENgetcount(countcode, &count);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = count;
}

#endif

#if FunENgetflowunits

////////////////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENgetflowunits( int* unitscode )
//
// Description:
//
// Retrieves a code number indicating the units used to express all flow rates.
//
// Arguments:
//
// unitscode:	value of a flow units code number (see below).
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
//
// Flow units codes are as follows:
//
// 0	= EN_CFS	cubic feet per second
// 1	= EN_GPM	gallons per minute
// 2	= EN_MGD	million gallons per day
// 3	= EN_IMGD	Imperial mgd
// 4	= EN_AFD	acre-feet per day
// 5	= EN_LPS	liters per second
// 6	= EN_LPM	liters per minute
// 7	= EN_MLD	million liters per day
// 8	= EN_CMH	cubic meters per hour
// 9	= EN_CMD	cubic meters per day
// Flow units are specified in the [OPTIONS] section of the EPANET Input file.
//
// Flow units in liters or cubic meters implies that metric units are used for all other quantities in addition to flow. Otherwise US units are employed. (See Units of Measurement).
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u:   [unitscode]=ENgetflowunits;
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	int unitscode;

	double *temp;
	int error;

	error = ENgetflowunits(&unitscode);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = unitscode;
}

#endif

#if FunENsetnodevalue

////////////////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENsetnodevalue( int index, int paramcode, float value )
//
// Description:
//
// Sets the value of a parameter for a specific node.
//
//
// Arguments:
//
//
// index:		node index
// paramcode:		parameter code (see below)
// value:	parameter value
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
//
// Node indexes are consecutive integers starting from 1.
//
// Node parameter codes consist of the following constants:

// EN_ELEVATION		0	Elevation
// EN_BASEDEMAND		1	Baseline demand
// EN_PATTERN		2	Time pattern index
// EN_EMITTER		3	Emitter coefficient
// EN_INITQUAL		4	Initial quality
// EN_SOURCEQUAL		5	Source quality
// EN_SOURCEPAT		6	Source pattern
// EN_SOURCETYPE		7	Source type:(See note below)
// EN_TANKLEVEL		8	Initial water level in tank
// Source types are identified with the following constants:
//
// EN_CONCEN			0
// EN_MASS			1
// EN_SETPOINT		2
// EN_FLOWPACED		3
// See [SOURCES] for a description of these source types.
//
//
// Values are supplied in units which depend on the units used for flow rate in the EPANET input file (see Units of Measurement).
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u:   [error]=ENsetnodevalue(nodeindex, paramcode, value);
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{
	int nodeindex, paramcode;
	float value;

	double *temp;
	int error;

	if (nrhs == 3)
	{

		temp = mxGetPr(prhs[0]);
		nodeindex = (int)(temp[0]);
		temp = mxGetPr(prhs[1]);
		paramcode = (int)(temp[0]);
		temp = mxGetPr(prhs[2]);
		value = (float)(temp[0]);
	}

	error = ENsetnodevalue(nodeindex, paramcode, value);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = error;
}

#endif

#if FunENsetlinkvalue

////////////////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENsetlinkvalue( int index, int paramcode, float value )
//
// Description:
//
// Sets the value of a parameter for a specific link.
//
// Arguments:
//
// index:	link index
// paramcode:	parameter code (see below)
// value:	parameter value
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
//
// Link indexes are consecutive integers starting from 1.
//
// Link parameter codes consist of the following constants:
//
// EN_DIAMETER		0	Diameter
// EN_LENGTH			1	Length
// EN_ROUGHNESS		2	Roughness coeff.
// EN_MINORLOSS		3	Minor loss coeff.
// EN_INITSTATUS		4	Initial link status(0 = closed, 1 = open)
// EN_INITSETTING	5	Pipe roughnessInitial pump speedInitial valve setting
// EN_KBULK			6	Bulk reaction coeff.
// EN_KWALL			7	Wall reaction coeff.
// EN_STATUS			11	Current pump or valve status(0 = closed, 1 = open)
// EN_SETTING		12	Current pump speed or valve setting
//
// Values are supplied in units which depend on the units used for flow rate in the EPANET input file (see Units of Measurement).
//
// Use EN_INITSTATUS and EN_INITSETTING to set the design value for a link's status or setting that exists prior to the start of a simulation. Use EN_STATUS and EN_SETTING to change these values while a simulation is being run (within the ENrunH - ENnextH loop).
//
// If a control valve has its status explicitly set to OPEN or CLOSED, then to make it active again during a simulation you must provide a new valve setting value using the EN_SETTING parameter.
//
// For pipes, either EN_ROUGHNESS or EN_INITSETTING can be used to change roughness.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u:   [error]=ENsetlinkvalue(linkindex, paramcode, value);
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{
	int linkindex, paramcode;
	float value;

	double *temp;
	int error;

	if (nrhs == 3)
	{

		temp = mxGetPr(prhs[0]);
		linkindex = (int)(temp[0]);
		temp = mxGetPr(prhs[1]);
		paramcode = (int)(temp[0]);
		temp = mxGetPr(prhs[2]);
		value = (float)(temp[0]);
	}

	error = ENsetlinkvalue(linkindex, paramcode, value);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = error;
}

#endif

#if FunENsolveH

/////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENsolveH( void )
//
// Description:
//
// Runs a complete hydraulic simulation with results for all time periods written to the binary Hydraulics file.
//
// Returns:
//
// Returns an error code.
//
//
// Notes:
//
// Use ENsolveH to generate a complete hydraulic solution which can stand alone or be used as input to a water quality analysis. It can also be followed by calls to ENsaveH and ENreport to write a report on hydraulic results to the report file. Do not use ENopenH, ENinitH, ENrunH, ENnextH, and ENcloseH in conjunction with ENsolveH.
//
//
// Example:
//
// ENopen("net1.inp", "net1.rpt", "");
// ENsolveH();
// ENsolveQ();
// ENreport();
// ENclose();
//
////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u: [error]=ENsolveH
//
//////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	double *temp;
	int error;

	error = ENsolveH();

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = error;
}

#endif

#if FunENopenH

/////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENopenH( void )
//
// Description:
//
// Opens the hydraulics analysis system.
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
// Call ENopenH prior to running the first hydraulic analysis using the ENinitH - ENrunH - ENnextH sequence. Multiple analyses can be made before calling ENcloseH to close the hydraulic analysis system.
//
// Do not call this function if ENsolveH is being used to run a complete hydraulic analysis.
//
////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u: [error]=ENopenH
//
//////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	double *temp;
	int error;

	error = ENopenH();

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = error;
}

#endif

#if FunENrunH

////////////////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENrunH( long* t )
//
// Description:
//
// Runs a single period hydraulic analysis, retrieving the current simulation clock time t.
//
// Arguments:
//
// t:	current simulation clock time in seconds.
//
// Returns:
//
// Returns an error code.
//
//
// Notes:
//
// Use ENrunH along with ENnextH in a do ..while loop to analyze hydraulics in each period of an extended period simulation. This process automatically updates the simulation clock time so treat t as a read-only variable.
//
// ENinitH must have been called prior to running the ENrunH - ENnextH loop.
//
// See ENnextH for an example of using this function.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u:   [error]=ENrunH(t);
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	long t;

	double *temp;
	int error;

	if (nrhs == 1)
	{

		temp = mxGetPr(prhs[0]);
		t = (long)(temp[0]);
	}

	error = ENrunH(&t);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = (double)t;
}

#endif

#if FunENnextH

////////////////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENnextH( long* tstep )
//
// Description:
//
// Determines the length of time until the next hydraulic event occurs in an extended period simulation.
//
// Arguments:
//
// tstep:	time (in seconds) until next hydraulic event occurs or 0 if at the end of the simulation period.
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
//
// This function is used in conjunction with ENrunH to perform an extended period hydraulic analysis (see example below).
//
// The value of tstep should be treated as a read-only variable. It is automatically computed as the smaller of:
//
// the time interval until the next hydraulic time step begins
//	the time interval until the next reporting time step begins
//	the time interval until the next change in demands occurs
//	the time interval until a tank becomes full or empty
//	the time interval until a control or rule fires
//
// Example:
//
// long t, tstep;
// ENopenH();
// ENinitH(0);
// do{   ENrunH(&t);
//
//   //Retrieve hydraulic results for time t
//
// ENnextH(&tstep);
// }
// while (tstep > 0);
// ENcloseH();
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u:   [error]=ENnextH(tstep);
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	long tstep;

	double *temp;
	int error;

	if (nrhs == 1)
	{

		temp = mxGetPr(prhs[0]);
		tstep = (long)(temp[0]);
	}

	error = ENnextH(&tstep);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = error;
}

#endif

#if FunENcloseH

/////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENcloseH( void )
//
// Description:
//
// Closes the hydraulic analysis system, freeing all allocated memory.
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
//
// Call ENcloseH after all hydraulics analyses have been made using ENinitH - ENrunH - ENnextH. Do not call this function if ENsolveH is being used.
//
////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u: [error]=ENcloseH
//
//////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	double *temp;
	int error;

	error = ENcloseH();

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = error;
}

#endif

#if FunENinitH

////////////////////////////////////////////////////////////////////////////////////////
// Declaration:
//
// int  ENinitH( int flag )
//
// Description:
//
// Initializes storage tank levels, link status and settings, and the simulation clock time prior to running a hydraulic analysis.
//
//
// Arguments:
//
//
// flag:	Two-digit flag indicating if hydraulic results will be saved to the hydraulics file (rightmost digit) and if link flows should be re-initialized.
//
// Returns:
//
// Returns an error code.
//
// Notes:
//
//
// Call ENinitH prior to running a hydraulic analysis using ENrunH and ENnextH.
//
// ENopenH must have been called prior to calling ENinitH.
//
// Do not call ENinitH if a complete hydraulic analysis is being made with a call to ENsolveH.
//
// Values of flag have the following meanings:
//
// 00	do not re-initialize flows, do not save results to file
// 01	do not re-initialize flows, save results to file
// 10	re-initialize flows, do not save results to file
// 11	re-initialize flows, save results to file
///////////////////////////////////////////////////////////////////////////////////////////////
//
// Poziv funkcije u MatLab-u: [error]=ENinitH(flag)
//
//////////////////////////////////////////////////////////////////////////////

void mexFunction(
	int nlhs,			  // Number of left hand side (output) arguments
	mxArray *plhs[],	  // Array of left hand side arguments
	int nrhs,			  // Number of right hand side (input) arguments
	const mxArray *prhs[] // Array of right hand side arguments
)
{

	int flag;

	double *temp;
	int error;

	if (nrhs == 1)
	{

		temp = mxGetPr(prhs[0]);
		flag = (int)(temp[0]);
	}

	error = ENinitH(flag);

	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	temp = mxGetPr(plhs[0]);
	*temp = error;
}

#endif
