#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>


int main (int argc, char *argv[]){

	const char* short_options = "hs::f:";

    struct numberOfOpt_t {
        int h;
        int s;
        int f;
    } numberOfOpt;

	const struct option long_options[] = {
		{"help",no_argument,NULL,'h'},
		{"size",optional_argument,NULL,'s'},
		{"file",required_argument,NULL,'f'},
		{NULL,0,NULL,0}
	};

	int rez;
	int option_index;

	while ((rez=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){

		switch(rez){
			case 'h': {
                if(numberOfOpt.h == 0) {
                    printf("This is demo help. Try -h or --help.\n");
                    (numberOfOpt.h)++;
				}
                break;

			};
			case 's': {
                if(numberOfOpt.s == 0) {
                    if(optarg!=NULL) {
                        printf("found size with value %s\n",optarg);
                        (numberOfOpt.s)++;
                    } else {
                        printf("found size without value\n");
                        (numberOfOpt.s)++;
                    }
                    break;
                }
                break;
			};

			case 'f': {
                if(numberOfOpt.f == 0) {
                    printf("file = %s\n",optarg);
                    (numberOfOpt.f)++;
                }
				break;
			};
			case '?': default: {
				printf("found unknown option\n");
				break;
			};
		};
	};
	return 0;
};

