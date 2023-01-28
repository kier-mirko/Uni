#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define N 20
#define K 4

void init_data(void);
void init_cluster_center(void);
void update_center(void);
void assign_object_to_cluster(void);
double calc_target_function(void);

typedef struct object {
	double a;
	double b;
	int center;
} object;

object data[N];
object center[K];
int cluster[N];
double alfa = 0.1;
int iter = 5000;

int
main(void)
{
	int n;
	srand((unsigned) time(NULL));

	init_data();
	double target = 0;
	double precision = 0;
	init_cluster_center();

	do {
		assign_object_to_cluster();
		update_center();
		target = calc_target_function();
		precision = fabs(target - precision);
		iter--;
	} while((precision > alfa) && iter > 0);

	for(int i = 0; i < N; ++i) {
		printf("%d ", data[i].center);
	}
	puts("\n");
	printf("iter: %d\n", iter);
	printf("target: %.2lf\n", target);
	printf("precision: %lf\n", precision);

}

void
init_data(void)
{
	for(int i = 0; i < N; ++i) {
		data[i] = (object) { .a = (double) rand() / RAND_MAX,
				     .b = (double) rand() / RAND_MAX};
	}
}

void
init_cluster_center(void)
{
	int used[K];

	for(int i = 0; i < K; ++i) {
		used[i] = -1;
	}
	for(int i = 0; i < K; ++i) {
		int index = rand() % N;
		for(int j = 0; j < K; ++j) {
			if(index == used[j]) {
				index = rand() % N;
				j = 0;
			}
		}
		center[i] = data[index];
	}
}

void
update_center(void)
{
	int center_nelem[K] = { 0 };

	for(int i = 0; i < K; ++i) {
		for(int j = 0; j < N; ++j) {
			if(data[j].center == i) {
				++center_nelem[i];
			}
		}
	}

	for(int i = 0; i < K; ++i) {
		double sum_a = 0;
		double sum_b = 0;
		for(int j = 0; j < N; ++j) {
			if(data[j].center == i) {
				sum_a += (double) data[j].a / center_nelem[i];
				sum_b += (double) data[j].b / center_nelem[i];
			}
		}
		center[i].a = sum_a;
		center[i].b = sum_b;
	}
}

void
assign_object_to_cluster(void)
{
	double d[K];


	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < K; ++j) {
			double distance = 0;
			distance += pow((data[i].a - center[j].a), 2);
			distance += pow((data[i].b - center[j].b), 2);
			d[j] = sqrt(distance);
		}

		double min = d[0];
		int min_index = 0;

		for(int j = 0; j < K; ++j) {
			if(d[j] < min) {
				min = d[j];
				min_index = j;
			}
		}

		data[i].center = min_index;
	}
}

double
calc_target_function(void)
{
	double distance_sum = 0;
	for(int i = 0; i < N; ++i) {
		double distance = 0;
		distance += pow((data[i].a - center[data[i].center].a), 2);
		distance += pow((data[i].b - center[data[i].center].b), 2);
		distance_sum += sqrt(distance);
	}
	return distance_sum;

}
