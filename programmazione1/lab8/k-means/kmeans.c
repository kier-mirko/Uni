#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define K 2

void init_data(size_t m, size_t n, double data[m][n]);
void init_cluster(size_t k, size_t m, size_t n, double center[k][n], double data[m][n]);
void update_center(size_t k, size_t m, size_t n, double center[k][n],
	double data[m][n], int cluster[m]);
void assign_object_to_cluster(size_t m, size_t n, size_t k, int cluster[m],
	double data[m][n], double center[k][n]);
double calc_target_function(size_t m, size_t n, size_t k, double data[m][n],
		     double center[k][n], int cluster[m]);

int
main(void)
{
	srand((unsigned) time(NULL));

	int m, n;
	printf("insert number of m: ");
	scanf("%d", &m);
	printf("insert number of n: ");
	scanf("%d", &n);

	double const alfa = 0.1;
	int iter = 1000;
	size_t const k = 2;

	double data[m][n];
	int cluster[m];
	double center[k][n];
	double target = 0;
	double precision = 0;

	init_data(m, n, data);
	init_cluster(k, m, n, center, data);



	do {
		assign_object_to_cluster(m, n, k, cluster, data, center);
		update_center(k, m, n, center, data, cluster);
		for(size_t i = 0; i < k; ++i) {
			for(size_t j = 0; j < n; ++j)
				printf("%lf ", center[i][j]);
			printf("\n");
		}

		printf("\n");
		target = calc_target_function(m, n, k, data, center, cluster);
		precision = fabs(target - precision);
		iter--;
	} while((precision > alfa) && iter > 0);

	for(int i = 0; i < m; ++i) {
		printf("%d ", cluster[i]);
	}
	puts("\n");
	printf("iter: %d\n", iter);
	printf("target: %.2lf\n", target);
	printf("precision: %lf\n", precision);


	return EXIT_SUCCESS;
}

void
init_data(size_t m, size_t n, double data[m][n])
{
	for(size_t i = 0; i < m; ++i) {
		for(size_t j = 0; j < n; ++j) {
			data[i][j] = (double) rand() / RAND_MAX;
		}
	}
}

void
init_cluster(size_t k, size_t m, size_t n, double center[k][n], double data[m][n])
{
	int used[k];
	for(int i = 0; i < k; ++i)
		used[i] = -1;

	for(size_t i = 0; i < k; ++i) {
		size_t row = rand() % m;
		for(size_t j = 0; j < k; ++j) {
			if(used[j] == row) {
				row = rand() % m;
				j = 0;
			}
		}

		for(size_t j = 0; j < n; ++j)
			center[i][j] = data[row][j];
	}
}

void
update_center(size_t k, size_t m, size_t n, double center[k][n], double data[m][n],
	      int cluster[m])
{
	int center_nelem[K] = { 0 };

	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < m; ++j) {
			if(cluster[j] == i)
				++center_nelem[i];
		}
	}


	for(size_t i = 0; i < k; ++i) {
		for(size_t j = 0; j < n; ++j) {
			double sum = 0;
			int nelem = 0;
			for(size_t l = 0; l < m; ++l) {
				if(cluster[l] == i) {
					sum += data[l][j];
				}
			}
			center[i][j] = sum / center_nelem[i];
		}
	}
}

void
assign_object_to_cluster(size_t m, size_t n, size_t k, int cluster[m], double data[m][n], double center[k][n])
{
	double d[k];

	for(size_t i = 0; i < m; ++i) {
		for(size_t j = 0; j < k; ++j) {
			double distance = 0;
			for(size_t l = 0; l < n; ++l) {
				distance += pow((data[i][l] - center[j][l]), 2);
			}
			d[j] = sqrt(distance);
		}

		double min = d[0];
		int min_index = 0;

		for(int j = 0; j < k; ++j) {
			if(d[j] < min) {
				min_index = j;
				min = d[min_index];
			}
		}

		cluster[i] = min_index;
	}
}


double
calc_target_function(size_t m, size_t n, size_t k, double data[m][n],
		     double center[k][n], int cluster[m])
{
	double distance = 0;
	double distance_sum = 0;
	for(size_t i = 0; i < m; ++i) {
		double distance  = 0;
		for(size_t j = 0; j < n; ++j)
			distance += pow((data[i][j] - center[cluster[i]][j]), 2);
		distance_sum += sqrt(distance);
	}
	return distance_sum;
}
