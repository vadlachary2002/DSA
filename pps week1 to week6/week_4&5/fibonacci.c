#include <stdio.h>
int main(){
	int n,n1=0,n2=1,n3=1;
	printf("Enter Nth term : ");
	scanf("%d",&n);
	printf("fibonocci series :\n%d\n%d\n",n1,n2);
	while(n3<n){
		printf("%d\n",n3);
		n1=n2;
		n2=n3;
		n3=n1+n2;
	}
	return 0;
}
