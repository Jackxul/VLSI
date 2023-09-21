/* map.c */
#include "map.h"
//Train Station Map File in C
/* charge fee table
 * <5   	20$
 * 5~8 		25$
 * 8~11 	30$
 * 11~14 	35$
 * 14~17 	40$
 * 17~20 	45$
 * 20~23 	50$
 * 23~26 	55$
 * 26~31 	60$
 * >31 		65$
 */
//calculate fee
//Need to be modified

//value
//0 : BR
//1 : BL
//2 : G
//3 : O
//4 : R
const int trans_BR[4][2] = {{9,405},{10,115},{11,216},{24,123}};
const int trans_R[6][2] = {{407,306},{408,210},{410,112},{411,214},{413,311},{405,9}};

int  stat_cal(char *in_stat , int in_no , char *out_stat , int out_no){
	int fee = 0;
	printf("in_stat = %c -> ",*in_stat);
	printf("%d\n",in_no);
	printf("out_stat = %c -> ",*out_stat);
	printf("%d\n",out_no);
/* ALGO */
 	int in_num = 409;
	int out_num = 24;
	int count_cal = 0;
	int total_dis = 0;

	fee = route_cal(in_num,out_num,total_dis,count_cal);
		
	return fee;
}

int test = 0;
int route_cal(int in_stat , int out_stat, int distance , int count){
	int in_color = in_stat/100;
	int out_color = out_stat/100;

	switch(in_color){
		case 0 :
			if(out_color == in_color){
				distance += abs(in_stat - out_stat);
			}
			else{
				int min = 9999;
				for(int i=0 ;i < sizeof(trans_BR)/sizeof(trans_BR[0]);i++){
					distance += abs(in_stat - trans_BR[i][0]);
					in_stat = trans_BR[i][1];
					distance += route_cal(in_stat,out_stat,distance,count);
					if(distance < min){
						min = distance;
					}

				}
				distance = min;
			}
			break;
			
		case 4 :
			if(out_color == in_color){
				distance += abs(in_stat - out_stat);
				test = abs(in_stat - out_stat);
			}
			else{
				int min = 9999;
				for(int i=0 ;i < sizeof(trans_R)/sizeof(trans_R[0]);i++){
					printf("distance = %d\n",distance);
					printf("in_stat = %d\n",in_stat);
					printf("trans_R = %d\n",trans_R[i][0]);
					distance += abs(in_stat - trans_R[i][0]);
					in_stat = trans_R[i][1];
					printf("min = %d\n",min);
					distance = route_cal(in_stat,out_stat,distance,count);
					if(distance < min){
						min = distance;
					}
					distance -= test;
					printf("distance2 = %d\n",distance);


				}
				distance = min;
			}
			break;
		default:
			break;
	}
	return distance;
}


void map(){






}
