#ifndef RAPPORT_H_
#define RAPPORT_H_

#define NUM_AXES    4 

typedef struct joyReport_tt {
    int16_t axis[NUM_AXES];
} joyReport_tt;

/*class Rapport{
	public:
		Rapport();
		int getaxis();
		void setaxis(int ligne, int valeur);

	private:
		int16_t axis[4];
};*/
#endif