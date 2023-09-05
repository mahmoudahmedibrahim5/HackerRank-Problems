#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
        printf("0x%x\n", int(A));
        
        int length = to_string(int(B)).length();
        length +=4;
        for(int i=0; i<15-length; i++)
            printf("_");
        printf((B>0)?"+":"-");
        printf("%.2lf\n", B);
        
        length = to_string(int(C)).length();
        double pow = 1;
        for(int i=1; i<length; i++)
            pow *= 10;
        printf("%.9lf", C/pow);
        if(length < 11)
            printf("E+0%d\n", length-1);
        else
            printf("E+%d\n", length-1);
	}
	return 0;

}