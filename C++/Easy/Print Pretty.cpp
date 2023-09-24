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
    printf("0x%lx\n", (long)(A));
    
    int length = to_string(long(B)).length();
    length +=4;
    for(int i=0; i<15-length; i++)
        printf("_");
    printf((B>0)?"+":"-");
    printf("%.2lf\n", B);
        
    cout << scientific << setprecision(9) << C << endl;
	}
	return 0;

}