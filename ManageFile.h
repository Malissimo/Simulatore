#ifndef ReadFile_h_included
#define ReadFile_h_included

int ReadEngine(double *datiengine);
void PrintEngine(double *datiengine);
int ReadPropeller(double *datipropeller, double *CSI,double *RD, double *CH, double *BA);
void PrintPropeller(double *datipropeller);
int ReadDBA(double*descvel);
#endif // FUNCTIONS_H_INCLUDED
