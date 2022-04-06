#include <stdio.h>
#include <stdlib.h>

/*
posa amaksia exeis;
na ftiaksw enan polidiastato(akerewn) pinaka pou na exeis seires oses ta amaksia kai stiles 3
me synartiseis: gia kathe amaksi na rwtisw ta kivika tous ipous kai tin diametro tis rodas kai na gemisw ton pinaka
display me morfi: 1. 1000cc, 90hp, 16cm
na vrw mo olwn twn amaksiwn
na vrw ton mo ipwn mono gia ta amaksia me ipous > 100
mo diametrwn mono gia ta amaksia me kivika > 1400
pio amaksi exei ta megista kivika kai na ektipwsw tous ipous tou
na metrisw posa amaksia exoun kivika katw apo 1000 kai ipous katw apo 90
sorting ton pinaka ws pros ta kivika se asc
ksana display
*/

void gemisma(int kiv_ip_diam[][3],int amaksia);
void display(int kiv_ip_diam[][3],int amaksia);
void mo_amaksia(int kiv_ip_diam[][3],int amaksia);
void mo_ipwn_panw_apo_100(int kiv_ip_diam[][3],int amaksia);
void mo_diam_me_kiv_panw_apo_1400(int kiv_ip_diam[][3],int amaksia);
void max_kiv(int kiv_ip_diam[][3],int amaksia);
void kiv_katw_apo_1000_kai_ipous_katw_apo_90(int kiv_ip_diam[][3],int amaksia);
void asc_sorting(int kiv_ip_diam[][3],int amaksia);
void display(int kiv_ip_diam[][3],int amaksia);

int main(){
	
	int amaksia,i;	
	printf("Posa amaksia exeis;\n");
	scanf("%i",&amaksia);
	int kiv_ip_diam[amaksia][3];
	
	display(kiv_ip_diam,amaksia);
	mo_amaksia(kiv_ip_diam,amaksia);
	mo_ipwn_panw_apo_100(kiv_ip_diam,amaksia);
	mo_diam_me_kiv_panw_apo_1400(kiv_ip_diam,amaksia);
	max_kiv(kiv_ip_diam,amaksia);
	kiv_katw_apo_1000_kai_ipous_katw_apo_90(kiv_ip_diam,amaksia);
	asc_sorting(kiv_ip_diam,amaksia);
	display(kiv_ip_diam,amaksia);
	
	return 0;
}

//gemisma
void gemisma(int kiv_ip_diam[][3],int amaksia){
	int i;
	int kivika,ipoi,diam_rodas;
	for (i=0; i<amaksia; i++){
		printf("Posa kivika einai to %i amaksi sou?\n",i+1);
		scanf("%i",&kivika);
		kiv_ip_diam[i][0]=kivika;
		printf("Posous ipous exei to %i amaksi sou?\n",i+1);
		scanf("%i",&ipoi);
		kiv_ip_diam[i][1]=ipoi;
		printf("Posa cm einai h diametros tis rodas sto %i amaksi sou?\n",i+1);
		scanf("%i",&diam_rodas);
		kiv_ip_diam[i][2]=diam_rodas;
	}
}

//display
void display(int kiv_ip_diam[][3],int amaksia){
	int i;
	printf("\n");
	for (i=0; i<amaksia; i++){
		printf("%i. %icc, %ihp, %icm\n",i+1,kiv_ip_diam[i][0],kiv_ip_diam[i][1],kiv_ip_diam[i][2]);
	}	
}

//mo xaraktiristikwn amaksiwn
void mo_amaksia(int kiv_ip_diam[][3],int amaksia){
	int i;
	double mo_kiv,mo_ip,mo_diam;
	double sum,sum1,sum2=0;
	for (i=0; i<amaksia; i++){
		sum=sum+kiv_ip_diam[i][0];
		sum1=sum1+kiv_ip_diam[i][1];
		sum2=sum2+kiv_ip_diam[i][2];
	}
	if (amaksia==0){
		mo_kiv=0;
		mo_ip=0;
		mo_diam=0;
	}
	else{
	mo_kiv=sum/amaksia;
	printf("O mo twn kivikwn einai %.2f\n",mo_kiv);
	mo_ip=sum1/amaksia;
	printf("O mo twn ipwn einai %.2f\n",mo_ip);
	mo_diam=sum2/amaksia;
	printf("O mo diametrwn einai %.2f\n",mo_diam);
	}
}

void mo_ipwn_panw_apo_100(int kiv_ip_diam[][3],int amaksia){
	double sum=0;
	int i;
	double mo;
	int count=0;
	for (i=0; i<amaksia; i++){
		if (kiv_ip_diam[i][1]>100){
			sum=sum+kiv_ip_diam[i][1];
			count++;
		}	
	}
	if (count==0){
		mo=0;
	}
	else{
		mo=sum/count;
	}
	printf("O mo gia tous ipous panw apo 100 einai %.2f\n",mo);
}

void mo_diam_me_kiv_panw_apo_1400(int kiv_ip_diam[][3],int amaksia){
	int i;
	double sum=0;
	double mo;
	int count=0;
	for (i=0; i<amaksia; i++){
		if (kiv_ip_diam[i][0]>1400){
			sum=sum+kiv_ip_diam[i][2];
			count++;
		}
	}
	if (count==0){
		mo=0;
	}
	else{
		mo=sum/count;

	}
	printf("O mo twn diametrwn me panw apo 1400 kivika einai %.2f\n",mo);	
}

void max_kiv(int kiv_ip_diam[][3],int amaksia){
	int i;
	int maxi;
	maxi=kiv_ip_diam[0][0];
	int pos=0;
	for (i=0; i<amaksia; i++){
		if (kiv_ip_diam[i][0]>maxi){
			maxi=kiv_ip_diam[i][0];
			pos=i;
		}
	}
	printf("Ta max kivika einai %i kai ta exei to amaksi %i, to opoio exei ipous %i\n",maxi,pos+1,kiv_ip_diam[pos][1]);
}

void kiv_katw_apo_1000_kai_ipous_katw_apo_90(int kiv_ip_diam[][3],int amaksia){
	int i;
	int count=0;
	for (i=0; i<amaksia; i++){
		if (kiv_ip_diam[i][0]<1000 && kiv_ip_diam[i][1]<90){
			count++;
		}
	}
	printf("Ta amaksia me kivika ligotera apo 1000 kai ipous ligoterous apo 90 einai %i",count);
}

//asc sorting pinaka ws pros kivika 
void asc_sorting(int kiv_ip_diam[][3],int amaksia){
	printf("\n");
	int i,j;
	int temp,temp1,temp2;
	for (i=0; i<amaksia-1; i++){
		for (j=0; j<amaksia-i-1; j++){
			if (kiv_ip_diam[j][0]>kiv_ip_diam[j+1][0]){
				//swap kivika
				temp=kiv_ip_diam[j][0];
				kiv_ip_diam[j][0]=kiv_ip_diam[j+1][0];
				kiv_ip_diam[j+1][0]=temp;
				//swap ipwn
				temp1=kiv_ip_diam[j][1];
				kiv_ip_diam[j][1]=kiv_ip_diam[j+1][1];
				kiv_ip_diam[j+1][1]=temp1;
				//swap diam
				temp2=kiv_ip_diam[j][2];
				kiv_ip_diam[j][2]=kiv_ip_diam[j+1][2];
				kiv_ip_diam[j+1][2]=temp2;
			}
		}
	}
}


	
