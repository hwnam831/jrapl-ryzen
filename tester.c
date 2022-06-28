#include "ryzen.h"

int main(int argc, char **argv) {
	
    init_rapl();
    int num_cores = total_cores/2;
    double *core_energy = (double*)malloc(sizeof(double)*total_cores/2);
    int i;
    for (i = 0; i < num_cores; i++) {
		core_energy[i] = read_core_energy(i);
	}
    double package_energy = read_package_energy();
    usleep(1000000);
    double core_sum = 0;
    for (i = 0; i < num_cores; i++) {
		double energy = read_core_energy(i);
        core_energy[i] = energy - core_energy[i];
        core_sum += core_energy[i];
	}
    package_energy = read_package_energy() - package_energy;
    for (i = 0; i < num_cores; i++) {
		printf("Core %d, current power consumption: %gW\n", i, core_energy[i]);
	}
    printf("Core total: %fW\t Package: %fW\n",core_sum, package_energy);
	close_rapl();
	
    free(core_energy);
	return 0;
}