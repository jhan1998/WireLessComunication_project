#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct car{
	vector<int> car;
	vector<int> direct;
	vector<float> x_point;
	vector<float> y_point;
	vector<int> p_best;
	vector<int> p_threshold;
	vector<int> p_entropy;
	vector<int> P_my;
	vector<int> p1;
	vector<int> p2;
	vector<int> p3;
	vector<int> p4;
	vector<bool> check;
};
int main() {
	car model;
	vector<int> best, threshold, entropy, my;
	float Pt = -50;
	float Px = -60; //1m
	float Pmin = -125;
	float b1x = 750;
	float b1y = 750;
	float b2x = 2250;
	float b2y = 750;
	float b3x = 750;
	float b3y = 2250;
	float b4x = 2250;
	float b4y = 2250;
	int car_num = 0;
	int count = 0;
	int bc = 0;
	int tc = 0;
	int ec = 0;
	int mc = 0;
	vector<float> b, t, e, m;
	srand(time(NULL));
	
	for( int i = 0; i < 86400; i++ ){
		
		int car_seed = ( rand() % 31 ) + 1;
		best.push_back(bc);
		threshold.push_back(tc);
		entropy.push_back(ec);
		my.push_back(mc);
		//新增車子 
		if( car_seed == 4 ){
			car_num += 1;
			count++;
			model.car.push_back(car_num);
			model.check.push_back(false);
			int point_seed = ( rand() % 12 ) + 1;
			int direct_seed = ( rand() % 6 ) + 1;
			float p1, p2, p3, p4;
			switch( point_seed ){
				case 1:
					model.x_point.push_back(750);
					model.y_point.push_back(0);
					if( direct_seed == 1 || direct_seed == 2 || direct_seed == 3 )
					model.direct.push_back(1);
					else if( direct_seed == 4 || direct_seed == 5 )
					model.direct.push_back(2);
					else if( direct_seed == 6 )
					model.direct.push_back(3);
					p1 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b1x, 2) + pow(model.y_point.back() - b1y, 2), 0.5 )));
					p2 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b2x, 2) + pow(model.y_point.back() - b2y, 2), 0.5 )));
					p3 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b3x, 2) + pow(model.y_point.back() - b3y, 2), 0.5 )));
					p4 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b4x, 2) + pow(model.y_point.back() - b4y, 2), 0.5 )));
					model.p1.push_back(p1);
					model.p2.push_back(p2);
					model.p3.push_back(p3);
					model.p4.push_back(p4);
					model.p_best.push_back(0);
					model.p_threshold.push_back(0);
					model.p_entropy.push_back(0);
					model.P_my.push_back(0);
					break;
				case 2:
					model.x_point.push_back(1500);
					model.y_point.push_back(0);
					if( direct_seed == 1 || direct_seed == 2 || direct_seed == 3 )
					model.direct.push_back(1);
					else if( direct_seed == 4 || direct_seed == 5 )
					model.direct.push_back(2);
					else if( direct_seed == 6 )
					model.direct.push_back(3);
					p1 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b1x, 2) + pow(model.y_point.back() - b1y, 2), 0.5 )));
					p2 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b2x, 2) + pow(model.y_point.back() - b2y, 2), 0.5 )));
					p3 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b3x, 2) + pow(model.y_point.back() - b3y, 2), 0.5 )));
					p4 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b4x, 2) + pow(model.y_point.back() - b4y, 2), 0.5 )));
					model.p1.push_back(p1);
					model.p2.push_back(p2);
					model.p3.push_back(p3);
					model.p4.push_back(p4);
					model.p_best.push_back(0);
					model.p_threshold.push_back(0);
					model.p_entropy.push_back(0);
					model.P_my.push_back(0);
					break;
				case 3:
					model.x_point.push_back(2250);
					model.y_point.push_back(0);
					if( direct_seed == 1 || direct_seed == 2 || direct_seed == 3 )
					model.direct.push_back(1);
					else if( direct_seed == 4 || direct_seed == 5 )
					model.direct.push_back(2);
					else if( direct_seed == 6 )
					model.direct.push_back(3);
					p1 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b1x, 2) + pow(model.y_point.back() - b1y, 2), 0.5 )));
					p2 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b2x, 2) + pow(model.y_point.back() - b2y, 2), 0.5 )));
					p3 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b3x, 2) + pow(model.y_point.back() - b3y, 2), 0.5 )));
					p4 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b4x, 2) + pow(model.y_point.back() - b4y, 2), 0.5 )));
					model.p1.push_back(p1);
					model.p2.push_back(p2);
					model.p3.push_back(p3);
					model.p4.push_back(p4);
					model.p_best.push_back(0);
					model.p_threshold.push_back(0);
					model.p_entropy.push_back(0);
					model.P_my.push_back(0);
					break;
				case 4:
					model.x_point.push_back(0);
					model.y_point.push_back(750);
					if( direct_seed == 1 || direct_seed == 2 || direct_seed == 3 )
					model.direct.push_back(3);
					else if( direct_seed == 4 || direct_seed == 5 )
					model.direct.push_back(1);
					else if( direct_seed == 6 )
					model.direct.push_back(4);
					p1 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b1x, 2) + pow(model.y_point.back() - b1y, 2), 0.5 )));
					p2 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b2x, 2) + pow(model.y_point.back() - b2y, 2), 0.5 )));
					p3 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b3x, 2) + pow(model.y_point.back() - b3y, 2), 0.5 )));
					p4 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b4x, 2) + pow(model.y_point.back() - b4y, 2), 0.5 )));
					model.p1.push_back(p1);
					model.p2.push_back(p2);
					model.p3.push_back(p3);
					model.p4.push_back(p4);
					model.p_best.push_back(0);
					model.p_threshold.push_back(0);
					model.p_entropy.push_back(0);
					model.P_my.push_back(0);
					break;
				case 5:
					model.x_point.push_back(0);
					model.y_point.push_back(1500);
					if( direct_seed == 1 || direct_seed == 2 || direct_seed == 3 )
					model.direct.push_back(3);
					else if( direct_seed == 4 || direct_seed == 5 )
					model.direct.push_back(1);
					else if( direct_seed == 6 )
					model.direct.push_back(4);
					p1 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b1x, 2) + pow(model.y_point.back() - b1y, 2), 0.5 )));
					p2 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b2x, 2) + pow(model.y_point.back() - b2y, 2), 0.5 )));
					p3 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b3x, 2) + pow(model.y_point.back() - b3y, 2), 0.5 )));
					p4 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b4x, 2) + pow(model.y_point.back() - b4y, 2), 0.5 )));
					model.p1.push_back(p1);
					model.p2.push_back(p2);
					model.p3.push_back(p3);
					model.p4.push_back(p4);
					model.p_best.push_back(0);
					model.p_threshold.push_back(0);
					model.p_entropy.push_back(0);
					model.P_my.push_back(0);
					break;
				case 6:
					model.x_point.push_back(0);
					model.y_point.push_back(2250);
					if( direct_seed == 1 || direct_seed == 2 || direct_seed == 3 )
					model.direct.push_back(3);
					else if( direct_seed == 4 || direct_seed == 5 )
					model.direct.push_back(1);
					else if( direct_seed == 6 )
					model.direct.push_back(4);
					p1 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b1x, 2) + pow(model.y_point.back() - b1y, 2), 0.5 )));
					p2 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b2x, 2) + pow(model.y_point.back() - b2y, 2), 0.5 )));
					p3 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b3x, 2) + pow(model.y_point.back() - b3y, 2), 0.5 )));
					p4 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b4x, 2) + pow(model.y_point.back() - b4y, 2), 0.5 )));
					model.p1.push_back(p1);
					model.p2.push_back(p2);
					model.p3.push_back(p3);
					model.p4.push_back(p4);
					model.p_best.push_back(0);
					model.p_threshold.push_back(0);
					model.p_entropy.push_back(0);
					model.P_my.push_back(0);
					break;
				case 7:
					model.x_point.push_back(750);
					model.y_point.push_back(3000);
					if( direct_seed == 1 || direct_seed == 2 || direct_seed == 3 )
					model.direct.push_back(4);
					else if( direct_seed == 4 || direct_seed == 5 )
					model.direct.push_back(3);
					else if( direct_seed == 6 )
					model.direct.push_back(2);
					p1 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b1x, 2) + pow(model.y_point.back() - b1y, 2), 0.5 )));
					p2 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b2x, 2) + pow(model.y_point.back() - b2y, 2), 0.5 )));
					p3 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b3x, 2) + pow(model.y_point.back() - b3y, 2), 0.5 )));
					p4 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b4x, 2) + pow(model.y_point.back() - b4y, 2), 0.5 )));
					model.p1.push_back(p1);
					model.p2.push_back(p2);
					model.p3.push_back(p3);
					model.p4.push_back(p4);
					model.p_best.push_back(0);
					model.p_threshold.push_back(0);
					model.p_entropy.push_back(0);
					model.P_my.push_back(0);
					break;
				case 8:
					model.x_point.push_back(1500);
					model.y_point.push_back(3000);
					if( direct_seed == 1 || direct_seed == 2 || direct_seed == 3 )
					model.direct.push_back(4);
					else if( direct_seed == 4 || direct_seed == 5 )
					model.direct.push_back(3);
					else if( direct_seed == 6 )
					model.direct.push_back(2);
					p1 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b1x, 2) + pow(model.y_point.back() - b1y, 2), 0.5 )));
					p2 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b2x, 2) + pow(model.y_point.back() - b2y, 2), 0.5 )));
					p3 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b3x, 2) + pow(model.y_point.back() - b3y, 2), 0.5 )));
					p4 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b4x, 2) + pow(model.y_point.back() - b4y, 2), 0.5 )));
					model.p1.push_back(p1);
					model.p2.push_back(p2);
					model.p3.push_back(p3);
					model.p4.push_back(p4);
					model.p_best.push_back(0);
					model.p_threshold.push_back(0);
					model.p_entropy.push_back(0);
					model.P_my.push_back(0);
					break;
				case 9:
					model.x_point.push_back(2250);
					model.y_point.push_back(3000);
					if( direct_seed == 1 || direct_seed == 2 || direct_seed == 3 )
					model.direct.push_back(4);
					else if( direct_seed == 4 || direct_seed == 5 )
					model.direct.push_back(3);
					else if( direct_seed == 6 )
					model.direct.push_back(2);
					p1 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b1x, 2) + pow(model.y_point.back() - b1y, 2), 0.5 )));
					p2 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b2x, 2) + pow(model.y_point.back() - b2y, 2), 0.5 )));
					p3 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b3x, 2) + pow(model.y_point.back() - b3y, 2), 0.5 )));
					p4 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b4x, 2) + pow(model.y_point.back() - b4y, 2), 0.5 )));
					model.p1.push_back(p1);
					model.p2.push_back(p2);
					model.p3.push_back(p3);
					model.p4.push_back(p4);
					model.p_best.push_back(0);
					model.p_threshold.push_back(0);
					model.p_entropy.push_back(0);
					model.P_my.push_back(0);
					break;
				case 10:
					model.x_point.push_back(3000);
					model.y_point.push_back(750);
					if( direct_seed == 1 || direct_seed == 2 || direct_seed == 3 )
					model.direct.push_back(2);
					else if( direct_seed == 4 || direct_seed == 5 )
					model.direct.push_back(4);
					else if( direct_seed == 6 )
					model.direct.push_back(1);
					p1 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b1x, 2) + pow(model.y_point.back() - b1y, 2), 0.5 )));
					p2 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b2x, 2) + pow(model.y_point.back() - b2y, 2), 0.5 )));
					p3 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b3x, 2) + pow(model.y_point.back() - b3y, 2), 0.5 )));
					p4 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b4x, 2) + pow(model.y_point.back() - b4y, 2), 0.5 )));
					model.p1.push_back(p1);
					model.p2.push_back(p2);
					model.p3.push_back(p3);
					model.p4.push_back(p4);
					model.p_best.push_back(0);
					model.p_threshold.push_back(0);
					model.p_entropy.push_back(0);
					model.P_my.push_back(0);
					break;
				case 11:
					model.x_point.push_back(3000);
					model.y_point.push_back(1500);
					if( direct_seed == 1 || direct_seed == 2 || direct_seed == 3 )
					model.direct.push_back(2);
					else if( direct_seed == 4 || direct_seed == 5 )
					model.direct.push_back(4);
					else if( direct_seed == 6 )
					model.direct.push_back(1);
					p1 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b1x, 2) + pow(model.y_point.back() - b1y, 2), 0.5 )));
					p2 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b2x, 2) + pow(model.y_point.back() - b2y, 2), 0.5 )));
					p3 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b3x, 2) + pow(model.y_point.back() - b3y, 2), 0.5 )));
					p4 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b4x, 2) + pow(model.y_point.back() - b4y, 2), 0.5 )));
					model.p1.push_back(p1);
					model.p2.push_back(p2);
					model.p3.push_back(p3);
					model.p4.push_back(p4);
					model.p_best.push_back(0);
					model.p_threshold.push_back(0);
					model.p_entropy.push_back(0);
					model.P_my.push_back(0);
					break;
				case 12:
					model.x_point.push_back(3000);
					model.y_point.push_back(2250);
					if( direct_seed == 1 || direct_seed == 2 || direct_seed == 3 )
					model.direct.push_back(2);
					else if( direct_seed == 4 || direct_seed == 5 )
					model.direct.push_back(4);
					else if( direct_seed == 6 )
					model.direct.push_back(1);
					p1 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b1x, 2) + pow(model.y_point.back() - b1y, 2), 0.5 )));
					p2 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b2x, 2) + pow(model.y_point.back() - b2y, 2), 0.5 )));
					p3 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b3x, 2) + pow(model.y_point.back() - b3y, 2), 0.5 )));
					p4 = -60 - ( 20 * log10( pow( pow(model.x_point.back() - b4x, 2) + pow(model.y_point.back() - b4y, 2), 0.5 )));
					model.p1.push_back(p1);
					model.p2.push_back(p2);
					model.p3.push_back(p3);
					model.p4.push_back(p4);
					model.p_best.push_back(0);
					model.p_threshold.push_back(0);
					model.p_entropy.push_back(0);
					model.P_my.push_back(0);
					break;
			}
		}
		if( model.car.size() > 0 ){
			//cout<< model.car.size()<<"　" <<model.car[0] <<" "<< model.direct[0]<< " " << model.x_point[0] << " " << model.y_point[0] << " " ;
			//cout << model.p1[0] << " " << model.p2[0]<< " " << model.p3[0]<< " " << model.p4[0] << " " << model.p_best[0]<< " " << model.P_my[0]<<" "<<bc<<" "<< tc <<" "<<mc << endl;
		for( int j = 0 ; j < model.car.size() ; j++ ){
			if( ( model.x_point[j] == 0 && model.y_point[j] == 750 ) 
				  || ( model.x_point[j] == 0 && model.y_point[j] == 1500 ) 
				  || ( model.x_point[j] == 0 && model.y_point[j] == 2250 )
				  || ( model.x_point[j] == 750 && model.y_point[j] == 0 ) 
				  || ( model.x_point[j] == 750 && model.y_point[j] == 750 ) 
				  || ( model.x_point[j] == 750 && model.y_point[j] == 1500 ) 
				  || ( model.x_point[j] == 750 && model.y_point[j] == 2250 ) 
				  || ( model.x_point[j] == 750 && model.y_point[j] == 3000 )
				  || ( model.x_point[j] == 1500 && model.y_point[j] == 0 ) 
				  || ( model.x_point[j] == 1500 && model.y_point[j] == 750 ) 
				  || ( model.x_point[j] == 1500 && model.y_point[j] == 1500 ) 
				  || ( model.x_point[j] == 1500 && model.y_point[j] == 2250 ) 
				  || ( model.x_point[j] == 1500 && model.y_point[j] == 3000 )
				  || ( model.x_point[j] == 2250 && model.y_point[j] == 0 )
				  || ( model.x_point[j] == 2250 && model.y_point[j] == 750 )
				  || ( model.x_point[j] == 2250 && model.y_point[j] == 1500 )
				  || ( model.x_point[j] == 2250 && model.y_point[j] == 2250 )
				  || ( model.x_point[j] == 2250 && model.y_point[j] == 3000 )
				  || ( model.x_point[j] == 3000 && model.y_point[j] == 750 )
				  || ( model.x_point[j] == 3000 && model.y_point[j] == 1500 )
				  || ( model.x_point[j] == 3000 && model.y_point[j] == 2250 ) ){
				  	int d_seed = ( rand() % 6 ) + 1;
				  	if( d_seed == 1 || d_seed == 2 || d_seed == 3 ){
				  		if( model.direct[j] == 1 )
				  		model.direct[j] = 1;
				  		else if( model.direct[j] == 2 )
				  		model.direct[j] = 2;
				  		else if( model.direct[j] == 3 )
				  		model.direct[j] = 3;
				  		else if( model.direct[j] == 4 )
				  		model.direct[j] = 4;
					}
					else if( d_seed == 4 || d_seed == 5 ){
						if( model.direct[j] == 1 )
				  		model.direct[j] = 2;
				  		else if( model.direct[j] == 2 )
				  		model.direct[j] = 4;
				  		else if( model.direct[j] == 3 )
				  		model.direct[j] = 1;
				  		else if( model.direct[j] == 4 )
				  		model.direct[j] = 3;
					}
					else if( d_seed == 6 ){
						if( model.direct[j] == 1 )
				  		model.direct[j] = 3;
				  		else if( model.direct[j] == 2 )
				  		model.direct[j] = 1;
				  		else if( model.direct[j] == 3 )
				  		model.direct[j] = 4;
				  		else if( model.direct[j] == 4 )
				  		model.direct[j] = 2;
					}
				}
				else if( model.x_point[j] == 3000 && model.y_point[j] == 3000 ) {
					if( model.direct[j] == 1 )
					    model.direct[j] = 2;
					else if( model.direct[j] == 3 )
					    model.direct[j] = 4;
				}
				else if( model.x_point[j] == 0 && model.y_point[j] == 0 ) {
					if( model.direct[j] == 4 )
					    model.direct[j] = 3;
					else if( model.direct[j] == 2 )
					    model.direct[j] = 1;
				}
				else if( model.x_point[j] == 0 && model.y_point[j] == 3000 ) {
					if( model.direct[j] == 1 )
					    model.direct[j] = 3;
					else if( model.direct[j] == 2 )
					    model.direct[j] = 4;
				}
				else if( model.x_point[j] == 3000 && model.y_point[j] == 0 ) {
					if( model.direct[j] == 3 )
					    model.direct[j] = 1;
					else if( model.direct[j] == 4 )
					    model.direct[j] = 2;
				}
				if( model.direct[j] == 1 )
				model.y_point[j] += 10;
				else if( model.direct[j] == 2 )
				model.x_point[j] -= 10;
				else if( model.direct[j] == 3 )
				model.x_point[j] += 10;
				else if( model.direct[j] == 4 )
				model.y_point[j] -= 10;
				if( model.x_point[j] < 0 || model.x_point[j] > 3000 || model.y_point[j] < 0 || model.y_point[j] > 3000 ){
					model.car.erase( model.car.begin() + j );
					model.direct.erase( model.direct.begin() + j );
					model.p1.erase( model.p1.begin() + j );
					model.p2.erase( model.p2.begin() + j );
					model.p3.erase( model.p3.begin() + j );
					model.p4.erase( model.p4.begin() + j );
					model.p_best.erase( model.p_best.begin() + j );
					model.p_entropy.erase( model.p_entropy.begin() + j );
					model.p_threshold.erase( model.p_threshold.begin() + j );
					model.x_point.erase( model.x_point.begin() + j );
					model.y_point.erase( model.y_point.begin() + j );
					continue;
				}
				float p1_new = -60 - ( 20 * log10( pow( pow(model.x_point[j] - b1x, 2) + pow(model.y_point[j] - b1y, 2), 0.5 )));
				float p2_new = -60 - ( 20 * log10( pow( pow(model.x_point[j] - b2x, 2) + pow(model.y_point[j] - b2y, 2), 0.5 )));
				float p3_new = -60 - ( 20 * log10( pow( pow(model.x_point[j] - b3x, 2) + pow(model.y_point[j] - b3y, 2), 0.5 )));
				float p4_new = -60 - ( 20 * log10( pow( pow(model.x_point[j] - b4x, 2) + pow(model.y_point[j] - b4y, 2), 0.5 )));
				model.p1[j] = p1_new;
				model.p2[j] = p2_new;
				model.p3[j] = p3_new;
				model.p4[j] = p4_new;
				if( model.x_point[j] == 2250 && model.y_point[j] == 2250 )
				    model.p4[j] = Px;
				if( model.x_point[j] == 2250 && model.y_point[j] == 750 )
				    model.p2[j] = Px;
				if( model.x_point[j] == 750 && model.y_point[j] == 2250 )
				    model.p3[j] = Px;
				if( model.x_point[j] == 750 && model.y_point[j] == 750 )
				    model.p1[j] = Px;
				//best
				if( model.p_best[j] == 1 ){
					if( model.p2[j] > model.p1[j] ){
						model.p_best[j] = 2;
						bc += 1;
					}
					else if( model.p3[j] > model.p1[j] ){
						model.p_best[j] = 3;
						bc += 1;
					}
					else if( model.p4[j] > model.p1[j] ){
						model.p_best[j] = 4;
						bc += 1;
					}
				}
				else if( model.p_best[j] == 2 ){
					if( model.p1[j] > model.p2[j] ){
						model.p_best[j] = 1;
						bc += 1;
					}
					else if( model.p3[j] > model.p2[j] ){
						model.p_best[j] = 3;
						bc += 1;
					}
					else if( model.p4[j] > model.p2[j] ){
						model.p_best[j] = 4;
						bc += 1;
					}
				}
				else if( model.p_best[j] == 3 ){
					if( model.p1[j] > model.p3[j] ){
						model.p_best[j] = 1;
						bc += 1;
					}
					else if( model.p2[j] > model.p3[j] ){
						model.p_best[j] = 2;
						bc += 1;
					}
					else if( model.p4[j] > model.p3[j] ){
						model.p_best[j] = 4;
						bc += 1;
					}
				}
				else if( model.p_best[j] == 4 ){
					if( model.p1[j] > model.p4[j] ){
						model.p_best[j] = 1;
						bc += 1;
					}
					else if( model.p2[j] > model.p4[j] ){
						model.p_best[j] = 2;
						bc += 1;
					}
					else if( model.p3[j] > model.p4[j] ){
						model.p_best[j] = 3;
						bc += 1;
					}
				}
				else if( model.p_best[j] == 0 ){
					if( model.p1[j] > model.p2[j] && model.p1[j] > model.p3[j] && model.p1[j] > model.p4[j] ){
						model.p_best[j] = 1;
						bc += 1;
					}
					else if( model.p2[j] > model.p1[j] && model.p2[j] > model.p3[j] && model.p2[j] > model.p4[j] ){
						model.p_best[j] = 2;
						bc += 1;
					}
					else if( model.p3[j] > model.p2[j] && model.p3[j] > model.p1[j] && model.p3[j] > model.p4[j] ){
						model.p_best[j] = 3;
						bc += 1;
					}
					else if( model.p4[j] > model.p2[j] && model.p4[j] > model.p3[j] && model.p4[j] > model.p1[j] ){
						model.p_best[j] = 4;
						bc += 1;
					}
				}
				// threshold
				if( model.p_threshold[j] == 1 ){
					if( model.p2[j] > model.p1[j] && model.p1[j] < -110 ){
						model.p_threshold[j] = 2;
						tc += 1;
					}
					else if( model.p3[j] > model.p1[j] && model.p1[j] < -110 ){
						model.p_threshold[j] = 3;
						tc += 1;
					}
					else if( model.p4[j] > model.p1[j] && model.p1[j] < -110 ){
						model.p_threshold[j] = 4;
						tc += 1;
					}
				}
				else if( model.p_threshold[j] == 2 ){
					if( model.p1[j] > model.p2[j] && model.p2[j] < -110 ){
						model.p_threshold[j] = 1;
						tc += 1;
					}
					else if( model.p3[j] > model.p2[j] && model.p2[j] < -110 ){
						model.p_threshold[j] = 3;
						tc += 1;
					}
					else if( model.p4[j] > model.p2[j] && model.p2[j] < -110 ){
						model.p_threshold[j] = 4;
						tc += 1;
					}
				}
				else if( model.p_threshold[j] == 3 ){
					if( model.p1[j] > model.p3[j] && model.p3[j] < -110 ){
						model.p_threshold[j] = 1;
						tc += 1;
					}
					else if( model.p2[j] > model.p3[j] && model.p3[j] < -110 ){
						model.p_threshold[j] = 2;
						tc += 1;
					}
					else if( model.p4[j] > model.p3[j] && model.p3[j] < -110 ){
						model.p_threshold[j] = 4;
						tc += 1;
					}
				}
				else if( model.p_threshold[j] == 4 ){
					if( model.p1[j] > model.p4[j] && model.p4[j] < -110 ){
						model.p_threshold[j] = 1;
						tc += 1;
					}
					else if( model.p2[j] > model.p4[j] && model.p4[j] < -110 ){
						model.p_threshold[j] = 2;
						tc += 1;
					}
					else if( model.p3[j] > model.p4[j] && model.p4[j] < -110 ){
						model.p_threshold[j] = 3;
						tc += 1;
					}
				}
				else if( model.p_threshold[j] == 0 ){
					if( model.p1[j] > model.p2[j] && model.p1[j] > model.p3[j] && model.p1[j] > model.p4[j] ){
						model.p_threshold[j] = 1;
						tc += 1;
					}
					else if( model.p2[j] > model.p1[j] && model.p2[j] > model.p3[j] && model.p2[j] > model.p4[j] ){
						model.p_threshold[j] = 2;
						tc += 1;
					}
					else if( model.p3[j] > model.p2[j] && model.p3[j] > model.p1[j] && model.p3[j] > model.p4[j] ){
						model.p_threshold[j] = 3;
						tc += 1;
					}
					else if( model.p4[j] > model.p2[j] && model.p4[j] > model.p3[j] && model.p4[j] > model.p1[j] ){
						model.p_threshold[j] = 4;
						tc += 1;
					}
				}				
				//entropy
				if( model.p_entropy[j] == 1 || model.p_entropy[j] == 0 ){
					if( model.p2[j] > (model.p1[j] + 5) ){
						model.p_entropy[j] = 2;
						ec += 1;
						//cout<<model.p2[j]<< " " << model.p1[j]<<" 1.1" <<endl;
					}
					else if( model.p3[j] > (model.p1[j] + 5) ){
						model.p_entropy[j] = 3;
						ec += 1;
						//cout<<model.p3[j]<< " " << model.p1[j]<< " 1.2" <<endl;
					}
					else if( model.p4[j] > (model.p1[j] + 5) ){
						model.p_entropy[j] = 4;
						ec += 1;
						//cout<<model.p4[j]<< " " << model.p1[j]<< " 1.3" <<endl;
					}
				}
				else if( model.p_entropy[j] == 2 || model.p_entropy[j] == 0 ){
					if( model.p1[j] > (model.p2[j] + 5) ){
						model.p_entropy[j] = 1;
						ec += 1;
						//cout<<model.p1[j]<< " " << model.p2[j]<< " 2.1" <<endl;
					}
					else if( model.p3[j] > (model.p2[j] + 5) ){
						model.p_entropy[j] = 3;
						ec += 1;
						//cout<<model.p3[j]<< " " << model.p2[j]<< " 2.2" <<endl;
					}
					else if( model.p4[j] > (model.p2[j] + 5) ){
						model.p_entropy[j] = 4;
						ec += 1;
						//cout<<model.p3[j]<< " " << model.p2[j]<< " 2.3" <<endl;
					}
				}
				else if( model.p_entropy[j] == 3 || model.p_entropy[j] == 0 ){
					if( model.p1[j] > (model.p3[j] + 5) ){
						model.p_entropy[j] = 1;
						ec += 1;
						//cout<<model.p1[j]<< " " << model.p3[j]<< " 3.1" <<endl;
					}
					else if( model.p2[j] > (model.p3[j] + 5) ){
						model.p_entropy[j] = 2;
						ec += 1;
						//cout<<model.p2[j]<< " " << model.p3[j]<< " 3.2" <<endl;
					}
					else if( model.p4[j] > (model.p3[j] + 5) ){
						model.p_entropy[j] = 4;
						ec += 1;
						//cout<<model.p4[j]<< " " << model.p3[j]<< " 3.3" <<endl;
					}
				}
				else if( model.p_entropy[j] == 4 || model.p_entropy[j] == 0 ){
					if( model.p1[j] > (model.p4[j] + 5) ){
						model.p_entropy[j] = 1;
						ec += 1;
						//cout<<model.p1[j]<< " " << model.p4[j]<< " 4.1" <<endl;
					}
					else if( model.p2[j] > (model.p4[j] + 5) ){
						model.p_entropy[j] = 2;
						ec += 1;
						//cout<<model.p2[j]<< " " << model.p4[j]<< " 4.2" <<endl;
					}
					else if( model.p3[j] > (model.p4[j] + 5) ){
						model.p_entropy[j] = 3;
						ec += 1;
						//cout<<model.p3[j]<< " " << model.p4[j]<< " 4.3" <<endl;
					}
				}
				//my
				if( model.P_my[j] == 1 || model.P_my[j] == 0 ){
					if( model.p2[j] > model.p1[j] + 5 && model.p2[j] > -105 ){
						model.P_my[j] = 2;
						
						mc += 1;
					}
					else if( model.p3[j] > model.p1[j] + 5 && model.p3[j] > -105 ){
						model.P_my[j] = 3;
						
						mc += 1;
					}
					else if( model.p4[j] > model.p1[j] + 5 && model.p4[j] > -105 ){
						model.P_my[j] = 4;
						
						mc += 1;
					}
					else if( model.p1[j] < -125 && model.P_my[j] != 0 ){
						if( model.p1[j] > model.p2[j] && model.p1[j] > model.p3[j] && model.p1[j] > model.p4[j] ){
						model.P_my[j] = 1;
						mc += 1;
					    }
					    else if( model.p2[j] > model.p1[j] && model.p2[j] > model.p3[j] && model.p2[j] > model.p4[j] ){
						model.P_my[j] = 2;
						mc += 1;
				        }
					    else if( model.p3[j] > model.p2[j] && model.p3[j] > model.p1[j] && model.p3[j] > model.p4[j] ){
						model.P_my[j] = 3;
						mc += 1;
				    	}
					    else if( model.p4[j] > model.p2[j] && model.p4[j] > model.p3[j] && model.p4[j] > model.p1[j] ){
						model.P_my[j] = 4;
						mc += 1;
					    }
					}
				}
				else if( model.P_my[j] == 2 || model.P_my[j] == 0 ){
					if( model.p3[j] > model.p2[j] + 5 && model.p3[j] > -105 ){
						model.P_my[j] = 3;
						
						mc += 1;
					}
					else if( model.p1[j] > model.p2[j] + 5 && model.p1[j] > -105 ){
						model.P_my[j] = 1;
						
						mc += 1;
					}
					else if( model.p4[j] > model.p2[j] + 5 && model.p4[j] > -105 ){
						model.P_my[j] = 4;
						mc += 1;
					}
					else if( model.p2[j] < -125 && model.P_my[j] != 0 ){
						if( model.p1[j] > model.p2[j] && model.p1[j] > model.p3[j] && model.p1[j] > model.p4[j] ){
						model.P_my[j] = 1;
						mc += 1;
					    }
					    else if( model.p2[j] > model.p1[j] && model.p2[j] > model.p3[j] && model.p2[j] > model.p4[j] ){
						model.P_my[j] = 2;
						mc += 1;
				        }
					    else if( model.p3[j] > model.p2[j] && model.p3[j] > model.p1[j] && model.p3[j] > model.p4[j] ){
						model.P_my[j] = 3;
						mc += 1;
				    	}
					    else if( model.p4[j] > model.p2[j] && model.p4[j] > model.p3[j] && model.p4[j] > model.p1[j] ){
						model.P_my[j] = 4;
						mc += 1;
					    }
					}
				}
				else if( model.P_my[j] == 3 || model.P_my[j] == 0 ){
					if( model.p1[j] > model.p3[j] + 5 && model.p1[j] > -105 ){
						model.P_my[j] = 1;
						
						mc += 1;
					}
					else if( model.p2[j] > model.p3[j] + 5 && model.p2[j] > -105 ){
						model.P_my[j] = 2;
						
						mc += 1;
					}
					else if( model.p4[j] > model.p3[j] + 5 && model.p4[j] > -105 ){
						model.P_my[j] = 4;
						
						mc += 1;
					}
					else if( model.p3[j] < -125 && model.P_my[j] != 0 ){
						if( model.p1[j] > model.p2[j] && model.p1[j] > model.p3[j] && model.p1[j] > model.p4[j] ){
						model.P_my[j] = 1;
						mc += 1;
					    }
					    else if( model.p2[j] > model.p1[j] && model.p2[j] > model.p3[j] && model.p2[j] > model.p4[j] ){
						model.P_my[j] = 2;
						mc += 1;
				        }
					    else if( model.p3[j] > model.p2[j] && model.p3[j] > model.p1[j] && model.p3[j] > model.p4[j] ){
						model.P_my[j] = 3;
						mc += 1;
				    	}
					    else if( model.p4[j] > model.p2[j] && model.p4[j] > model.p3[j] && model.p4[j] > model.p1[j] ){
						model.P_my[j] = 4;
						mc += 1;
					    }
					}
				}
				else if( model.P_my[j] == 4 || model.P_my[j] == 0 ){
					if( model.p1[j] > model.p4[j] + 5 && model.p1[j] > -105 ){
						model.P_my[j] = 1;
						
						mc += 1;
					}
					else if( model.p2[j] > model.p4[j] + 5 && model.p2[j] > -105 ){
						model.P_my[j] = 2;
						
						mc += 1;
					}
					else if( model.p3[j] > model.p4[j] + 5 && model.p3[j] > -105){
						model.P_my[j] = 3;
						
						mc += 1;
					}
					else if( model.p4[j] < -125 && model.P_my[j] != 0 ){
						if( model.p1[j] > model.p2[j] && model.p1[j] > model.p3[j] && model.p1[j] > model.p4[j] ){
						model.P_my[j] = 1;
						mc += 1;
					    }
					    else if( model.p2[j] > model.p1[j] && model.p2[j] > model.p3[j] && model.p2[j] > model.p4[j] ){
						model.P_my[j] = 2;
						mc += 1;
				        }
					    else if( model.p3[j] > model.p2[j] && model.p3[j] > model.p1[j] && model.p3[j] > model.p4[j] ){
						model.P_my[j] = 3;
						mc += 1;
				    	}
					    else if( model.p4[j] > model.p2[j] && model.p4[j] > model.p3[j] && model.p4[j] > model.p1[j] ){
						model.P_my[j] = 4;
						mc += 1;
					    }
					}
				}
			}
		}
		float powerb, powert, powere,powerm;
		powerb = 0;
		powert = 0;
		powere = 0;
		powerm = 0;
		for( int j = 0 ; j < model.car.size() ; j++ ){
			if( model.p_best[j] == 1 )
				    powerb += model.p1[j];
				else if( model.p_best[j] == 2 )
				    powerb += model.p2[j];
				else if( model.p_best[j] == 3 )
				    powerb += model.p3[j];
				else if( model.p_best[j] == 4 )
				    powerb += model.p4[j];
			if( model.p_threshold[j] == 1 )
				    powert += model.p1[j];
			else if( model.p_threshold[j] == 2 )
				    powert += model.p2[j];
			else if( model.p_threshold[j] == 3 )
				    powert += model.p3[j];
			else if( model.p_threshold[j] == 4 )
				    powert += model.p4[j];
			if( model.p_entropy[j] == 1 )
				    powere += model.p1[j];
			else if( model.p_entropy[j] == 2 )
				    powere += model.p2[j];
			else if( model.p_entropy[j] == 3 )
				    powere += model.p3[j];
			else if( model.p_entropy[j] == 4 )
				    powere += model.p4[j];
			if( model.P_my[j] == 1 )
				    powerm += model.p1[j];
			else if( model.P_my[j] == 2 )
				    powerm += model.p2[j];
			else if( model.P_my[j] == 3 )
				    powerm += model.p3[j];
			else if( model.P_my[j] == 4 )
				    powerm += model.p4[j];
				powerb = powerb/model.car.size();
				powert = powert/model.car.size();
				powere = powere/model.car.size();
				powerm = powerm/model.car.size();
				b.push_back(powerb);
				t.push_back(powert);
				e.push_back(powere);
				m.push_back(powerm);
		}
	}
	/*for(int i = 0 ; i < model.car.size() ; i++ ){
	    cout << model.car[i] << " ";
	    cout << model.direct[i] << " ";
	    cout << model.p1[i] << " ";
	    cout << model.p2[i] << " ";
	    cout << model.p3[i] << " ";
	    cout << model.p4[i] << " ";
	    cout << model.p_best[i] << " ";
	    cout << model.x_point[i]<<" ";
	    cout << model.y_point[i]<<endl;
	}*/
	cout << model.p_threshold.size() << endl;
	cout << model.p_entropy.size() << endl;
	cout << model.p_best.size() << endl;
	cout << model.p2.size() << endl;
	cout << model.p3.size() << endl;
	cout << model.p4.size() << endl;
	cout << model.car.size() << endl;
	cout << model.car.back() << endl;
	cout << model.direct.size() << endl;
	cout << model.x_point.size()<<endl;
	cout << model.y_point.size()<<endl;
	cout << best.back() << endl;
	cout << threshold.back() << endl;
	cout << entropy.back() << endl;
	cout << my.back() << endl; 
	float bcount = 0 ;
	float tcount = 0;
	float ecount = 0;
	float mcount = 0;
	for(int i = 0 ; i < b.size() ; i++ )
	bcount += b[i]; 
	for(int i = 0 ; i < t.size() ; i++ )
	tcount += t[i]; 
	for(int i = 0 ; i < e.size() ; i++ )
	ecount += e[i]; 
	for(int i = 0 ; i < m.size() ; i++ )
	mcount += m[i]; 
	cout << bcount/86400 << " " << tcount/86400 << " " << ecount/86400 << " " << mcount/86400 <<endl;
	fstream file;
	file.open("best.txt",ios::out);
	if(file.fail())
	   cout<<"didin't open"<<endl;
	else
	for(int i = 0 ; i < best.size() ; i++ )
	    file << best[i] <<endl;
	
	file.close();
	
	fstream file1;
	file1.open("threshold.txt",ios::out);
	if(file1.fail())
	   cout<<"didin't open"<<endl;
	else
	for(int i = 0 ; i < threshold.size() ; i++ )
	    file1 << threshold[i] <<endl;
	
	file1.close();
	
	file1.open("entropy.txt",ios::out);
	if(file1.fail())
	   cout<<"didin't open"<<endl;
	else
	for(int i = 0 ; i < entropy.size() ; i++ )
	    file1 << entropy[i] <<endl;
	
	file1.close();
	
	file1.open("my.txt",ios::out);
	if(file1.fail())
	   cout<<"didin't open"<<endl;
	else
	for(int i = 0 ; i < my.size() ; i++ )
	    file1 << my[i] <<endl;
	
	file1.close();
	
	return 0;
}
