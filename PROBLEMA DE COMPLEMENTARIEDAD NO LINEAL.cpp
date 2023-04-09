
struct nodo{
	char variable;
	nodo *sig;
	float coeficiente;
	float exponente;
};

nodo *ins_f(nodo *);

void recorre(nodo *);
float calculo(nodo *,float ,float);

/*
int main(){
	nodo *p=NULL;
	nodo *o=NULL;
	int i,n,m,opc,num;
	float j,k,f1,f2;
	float A[10][2];
	system("cls");
	cout<<"***************************************************"<<endl;
	cout<<"******PROBLEMA DE COMPLEMENTARIEDAD NO LINEAL******"<<endl;
	cout<<"***************************************************"<<endl;
	cout<<"Ingrese nro de monomios/terminos de la 1era funcion: "<<endl;
	cin>>n;
	
	for(i=0;i<n;i++){
		cout<<"Termino ["<<i+1<<"]: "<<endl;
		p=ins_f(p);
	}
	cout<<endl;
	cout<<"Ingrese nro de monomios/terminos de la 2da funcion: "<<endl;
	cin>>m;
	
	for(i=0;i<m;i++){
		cout<<"Termino ["<<i+1<<"]: "<<endl;
		o=ins_f(o);
	}

	system("pause");
	system("cls");
	cout<<"***************************************************"<<endl;
	cout<<"******PROBLEMA DE COMPLEMENTARIEDAD NO LINEAL******"<<endl;
	cout<<"***************************************************"<<endl;
	cout<<"Primera funcion: "<<endl;
	recorre(p);
	cout<<endl;
	cout<<"Segunda funcion: "<<endl;
	recorre(o);
	cout<<endl;
	cout<<"Modo de calculo: "<<endl;
	cout<<"1. Calculo puntos  en especifico . . . "<<endl;
	cout<<"2. Calculo todos los puntos posibles . . . "<<endl;
	cin>>opc;
	switch(opc){
		case 1:
			cout<<"Ingrese numero de puntos: "<<endl;
			cin>>num;
			cout<<endl<<"Digite los puntos: "<<endl;
			for(i=0;i<num;i++){
				cout<<"Punto ["<<i+1<<"]: "<<endl;
				cout<<"x = ";
				cin>>A[i][1];
				cout<<"y = ";
				cin>>A[i][2];
			}
			cout<<endl;
			cout<<"Comprobando puntos . . . "<<endl<<endl;
			for(i=0;i<num;i++){
				cout<<"Punto ["<<i+1<<"]: "<<endl;
				cout<<"x = "<<A[i][1];
				cout<<endl;
				cout<<"y = "<<A[i][2];
				f1=calculo(p,A[i][1],A[i][2]);
				f2=calculo(o,A[i][1],A[i][2]);
				if(f1>=0 && f2>=0){
					if(A[i][1]*f1==0 && A[i][2]*f2==0){
						cout<<endl;
						cout<<"matriz x: "<<A[i][1]<<" - "<<A[i][2]<<endl;
						cout<<"matriz fx: "<<f1<<" - "<<f2<<endl;
						cout<<"Cumple con las dos condiciones de factibilidad y complementariedad";
					}
				}
				cout<<endl<<endl;
			}
			
			system("pause");
		break;
		case 2:
				for(j=0;j<=2.1;j=j+0.1){
					for(k=0;k<=2.1;k=k+0.1){
						f1=calculo(p,j,k);
						f2=calculo(o,j,k);
						if(f1>=0 && f2>=0){
							if(j*f1==0 && k*f2==0){
								cout<<"matriz x: "<<j<<" - "<<k<<endl;
								cout<<"matriz fx: "<<f1<<" - "<<f2<<endl;
								cout<<"Cumple con las dos condiciones de factibilidad y complementariedad"<<endl<<endl;
							}
						}
					}
				}
			system("pause");
		break;
	}while(opc!=2);
	return 0;
}
*/
nodo *ins_f(nodo *p){
	nodo *q,*r;
	q=new (nodo);
	q->sig=NULL;
	cout<<"Coeficiente : ";
	cin>>q->coeficiente;
	cout<<"Variable : ";
	cin>>q->variable;
	cout<<"Exponente : ";
	cin>>q->exponente;
	r=p;
	if(r!=NULL){
		while(r->sig!=NULL){
			r=r->sig;
		}
		r->sig=q;
	}
	else{
		p=q;
	}
	return (p);
}
void recorre(nodo *p){
	nodo *q;
	int x;
	x=0;
	q=p;
	while(q!=NULL){
		if(x!=0)
		{
			if(q->coeficiente>0)
			{
				cout<<" + ";
			}
			else{
				cout<<" - ";
			}
		}
		if(q->coeficiente>0)
		{
			cout<<q->coeficiente;
		}
		else{
			cout<<-1*q->coeficiente;
		}
		cout<<"*";
		cout<<q->variable;
		cout<<"^";
		cout<<q->exponente;
		q=q->sig;
		x=x+1;
	}
}

float calculo(nodo *p,float a, float b){
	nodo *q;
	float ca=0;
	float z;
	q=p;

	while(q!=NULL){
		if(q->variable=='x'){
			ca=ca+(q->coeficiente*(pow(a,q->exponente)));
		}
		if(q->variable=='y'){
			ca=ca+(q->coeficiente*(pow(b,q->exponente)));
		}
		if(ca>=-0.00009 && ca<=0.00003){
			ca=0;
		}
		q=q->sig;
	}
	return(ca);
}
