#include <iostream>
#include <cmath>

using namespace std;

float getB(float xc, float yc, float x1, float y1, float x2, float y2, float R){
	float b = 2*((x2 - x1)*(x1 - xc) + (y2 - y1)*(y1 - yc));
	return b;
}

float getA(float xc, float yc, float x1, float y1, float x2, float y2, float R){
	float a = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
	return a;
}

float getC(float xc, float yc, float x1, float y1, float x2, float y2, float R){
	float c = (x1 - xc)*(x1 - xc) + (y1 - yc)*(y1 - yc) - R*R;
	return c;
}

bool isPositive(float a, float b, float c){
	float d = b*b - 4*a*c;
	if(d < 0){
		return false;
	}
	else if(d == 0){
		float root = -b/(2*a);
		
		if(root >= 0 && root <= 1){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		d = sqrt(d);
		float root = (-b + d)/(2*a);
		if(root >= 0 && root <= 1){
			return true;
		}
		else{
			root = (-b - d)/(2*a);
			if(root >= 0 && root <= 1){
				return true;
			}
			else{
				return false;
			}
		}
	}
}

int main(){
	int T;
	cin >> T;

	while(T--){
		float xc, yc, R;
		cin >> xc >> yc >> R;
		float x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		
		float a, b, c;
		//side 1
		a = getA(xc, yc, x1, y1, x2, y2, R);
		b = getB(xc, yc, x1, y1, x2, y2, R);
		c = getC(xc, yc, x1, y1, x2, y2, R);
		if(isPositive(a, b, c)){
			cout << "YES" << endl;
		}
		else{
			//side 2
			a = getA(xc, yc, x1, y1, x3, y3, R);
			b = getB(xc, yc, x1, y1, x3, y3, R);
			c = getC(xc, yc, x1, y1, x3, y3, R);
			if(isPositive(a, b, c)){
				cout << "YES" << endl;
			}
			else{
				//side 3
				a = getA(xc, yc, x3, y3, x2, y2, R);
				b = getB(xc, yc, x3, y3, x2, y2, R);
				c = getC(xc, yc, x3, y3, x2, y2, R);
				if(isPositive(a, b, c)){
					cout << "YES" << endl;
				}
				else{
					cout << "NO" << endl;
				}
			}
		}
	}
}