#include <stdio.h>
#include <math.h>

main(argc, argv) 
int argc;
char *argv[];
{
   double *times, avg_time;
   int *cuts, cut, num_runs, i, tot_cut, min_cut;
   FILE *fr;
   char line[80], temp[80];

   num_runs = atoi(argv[1]);
   cuts = (int *) calloc(num_runs,sizeof(int));
   times = (double *) calloc(num_runs,sizeof(double));
   for (i=0; i<num_runs; i++) {
       cuts[i] = 0;
       times[i] = 0;
   } 
   fr = fopen(argv[2], "r");
   if (fr == NULL) 
      fprintf(stderr, "Could not open file\n");
   for (i=0; i<num_runs; i++) {
       fscanf(fr, "%*s %*s %*s %d%*s %s %*s %*d\n", &cut, temp);
       cuts[i] = cut;
       times[i] = atof(temp);
   }
   tot_cut = 0;
   min_cut = 9999999;
   avg_time = 0;
   for (i=0; i<num_runs; i++) {
       tot_cut += cuts[i];
       if (min_cut > cuts[i]) min_cut = cuts[i];
       avg_time += times[i];
   }
   printf("Min cut %d,  Avg cut %.2f,  Avg time %.2f\n", min_cut, 
     ((float) tot_cut)/num_runs, avg_time/num_runs);
}

