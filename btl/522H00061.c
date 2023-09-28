#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.1415926535

int frnum(int n, int ld){
	int i, sn=0, sld=0;
	for(i=1; i<n; i++){
		if(n%i==0)
			sn+=i;
	}
	for(i=1; i<ld; i++){
		if(ld%i==0)
			sld+=i;
	}
	if(sn==ld && sld==n){
		return 0;
	}
	else
		return 1;	
}

void main(){
	int n, dc, dg, ld, bc=0, bg=0, i, j, l, bcbg, a;
	double nd, nd1, nd2;
	char w[10];
	FILE *fi,*fo;
	fi = fopen("input.inp", "r");
	
	fscanf(fi, "%d %d %d %d %s", &n, &dc, &dg, &ld, w);
	fclose(fi);
	
	if(n<0 || n>1001|| ld<0 ||ld>300)
	{	
		fo = fopen("output.out","w");
		fprintf(fo,"-1 -1 %d",n);	
		fclose(fo);
	}
	else{
		int nc=dc*dc;
		float ng=(dg*dg*PI)/4;
		int mbc=n/nc, mbg=(int) n/ng;
		float min=n;
		
		
		if(strcmp(w, "Wind") == 0){
			
			fo = fopen("output.out","w");
			
			for (i=mbc ; i>=0 ; i--){    
			                  
				for (j=0 ; j<=mbg ; j++){    
				            
					if (i+j<=ld){
						
						nd = n - i*nc - j*ng;	
									
						if (nd>=0){
							if(nd<=min){
								if (i>j){
									min=nd;
									bc=i;
									bg=j;
								}
							}	
						}
						else break;
					}
					else break;
				}
			}
			fprintf(fo ,"%d %d %.3f" ,bc ,bg ,min);
			fclose(fo);	 	
		}
		
		
		if(strcmp(w, "Rain") == 0){
			fo = fopen("output.out","w");
						
			bcbg = n / (nc+ng);
			if(bcbg > ld/2) bcbg = ld/2;
			bc = bg = bcbg;
			if(nc<1) bc=0;
			if(ng<1) bg=0;
			ld = ld - bc - bg;
				nd1 = n - bc*nc - bc*ng; 
				
				if((nd1>=nc || nd1>ng) && nc>ng )
				{
					a = nd1/nc;
					if(a>ld) a=ld;
					
					bc = bcbg + a;
					nd2 = nd1 - a*nc;
					if(nd2>=ng)
					{
						a = nd2/ng;
						if(a>ld) a=ld;
						bg = bg + a;
						nd = nd2 - a*ng;
					}
					else nd = nd2;
				}
				else if((nd1>=nc || nd1>ng) && ng>nc)
				{
					a = nd1/ng;
					if(a>ld) a=ld;
					
					bg = bcbg + a;
					nd2 = nd1 - a*ng;
					if(nd2>=nc)
					{
						a = nd2/nc;
						if(a>ld) a=ld;
						bc = bc + a;
						nd = nd2 - a*nc;
					}
					else nd = nd2;
				}
				else
				{
					nd = nd1;
				}
			fprintf(fo ,"%d %d %.3f" ,bc ,bg ,nd);
			fclose(fo);
		}
		
		if(strcmp(w, "Cloud") == 0){				
			fo = fopen("output.out","w");
			
			if (frnum(n,ld)==0)
				fprintf(fo ,"0 0 %d" ,n);
				
			else {
				for (i=mbg ; i>=0 ; i--){
					for (j=0 ; j<=mbc ; j++){
						if (i+j<=ld){
							nd = n - i*ng - j*nc;
							if (nd>=0){
								if(nd<=min){
									min=nd;
									bc=j;
									bg=i;
								}
							}
							else break;
						}
						else break;
					}
				}
				fprintf(fo ,"%d %d %.3f" ,bc ,bg ,min);
			}
			fclose(fo);
		}
			
		if(strcmp(w, "Fog") == 0){
			fo = fopen("output.out","w");
			fprintf(fo,"%d %d %.3f", dc, dg, n);	
			fclose(fo);
		}
		
		if(strcmp(w, "Sun") == 0){
			int G, H, X;
			G = dc % 6;
			H = ld % 5;
			int a[5][6]={{5,7,10,12,15,20} ,{20,5,7,10,12,15} ,{15,20,5,7,10,12} ,{12,15,20,5,7,10} ,{10,12,15,20,5,7}};
			X = a[H][G];
			n = n + n*(X/100.0);
			ld = ld-X;
			
			if((dc+dg)%3==0)
			{
				fo = fopen("output.out","w");			
				if (mbc>mbg)
					l=mbc;
				else l=mbg;
				
				for (i=l ; i>=0 ; i--){
					for (j=i+2; j>=i-2; j--){  
						if (i+j<=ld){
							nd = n - i*nc - j*ng;
							if (nd>=0){
								if(nd<=min){
									if(i>j){
										min=nd;
										bc=i;
										bg=j;
									}
								}
							}
						}
						else break;
					}
				}	
				fprintf(fo ,"%d %d %.3f" ,bc ,bg ,min);
				fclose(fo);
			}
			
			else if ((dc+dg)%3==1)
			{
				fo = fopen("output.out","w");
				for (i=mbc ; i>=0 ; i--){                      
					for (j=0 ; j<=mbg ; j++){                
						if (i+j<=ld){
							nd = n - i*nc - j*ng;				
							if (nd>=0){
								if(nd<=min){
									if(i>j){
										min=nd;
										bc=i;
										bg=j;
									}
								}
							}
							else break;
						}
						else break;
					}
				}
				fprintf(fo ,"%d %d %.3f" ,bc ,bg ,min);
				fclose(fo);	
			}	
					
			else 
			{				
				fo = fopen("output.out","w");
			
				if (frnum(n,ld)==0)
					fprintf(fo ,"0 0 %d" ,n);
				
				else {
					for (i=mbg ; i>=0 ; i--){
						for (j=0 ; j<=mbc ; j++){
							if (i+j<=ld){
								nd = n - i*ng - j*nc;
								if (nd>=0){
									if(nd<=min){
										min=nd;
										bc=j;
										bg=i;
									}
								}
								else break;
							}
							else break;
						}
					}
					fprintf(fo ,"%d %d %.3f" ,bc ,bg ,min);
				}
				fclose(fo);
			}
		}
	}
}
