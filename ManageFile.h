#ifndef ReadFile_h_included
#define ReadFile_h_included

int ReadEngine(double *datiengine);
void PrintEngine(double *datiengine);
int ReadPropeller(double *datipropeller, double *CSI,double *RD, double *CH, double *BA);
void PrintPropeller(double *datipropeller);
int ReadDBA(double*descvel, double *deflec, double *massacomb,
            double *alpha, double *CX,double *CY,double *CZ,double *Cl,double *Cm,double *Cn,
            double *CXA	,double *CXAP,double *CXU,double *CXQ,double *CXB,double *CXP,double *CXR,
            double *CYB,double *CYBP,double *CYP,double *CYR,double *CYA,double *CYQ,
            double *CZALPHA,double *CZAP,double *CZU,double *CZQ,double *CZB,double *CZP,double *CZR,
            double *ClB,double *ClBP,double *ClP,double *ClR,double *ClA,double *ClQ,
            double *CmA,double *CmAP,double *CmU,double *CmQ,double *CmB,double *CmP,double *CmR,
            double *CnB,double *CnBP,double *CnP,double *CnR,double *CnA,double *CnQ,
            double *CXde,double *CXdle,double *CZde,double *CZdle,double *CYda,double *CYdr,
            double *Clda,double *Cldr,double *Cmde,double *Cmdle,double *Cnda,double *Cndr,
            double *CXom,double *CYom,double *CZom,double *Clom,double *Cmom,double *Cnom);
#endif // FUNCTIONS_H_INCLUDED
