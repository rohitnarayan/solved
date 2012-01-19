#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define foreach(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef long long int lli;
typedef pair<int,int> ii;

const int MAXS = 10010;
double H[MAXS], A[MAXS];
// H[s] = probability that candy will remain in home state after s moves
// A[s] = probability that candy will remain in away state after s moves

class CandyBox {
public:
    vector <double> expectedScore(int C, vector <int> score, int S) {
        int n = score.size();
        vector<double> exp(n);

        // handle n == 1 case
        if(n == 1){
            exp[0] = score[0];
            return exp;
        }

        double x = C, y = (n-1)*C;
        double q = y;
        q /= (x+y)*(x+y-1)/2;
        double p = 1.0 - q;
        
        H[0] = 1, A[0] = 0;
        for (int s = 1; s <= S; s++){
            H[s] = p*H[s-1] + (q/(n-1))*A[s-1];
            A[s] = q*H[s-1] + (p + (((n-2)*q)/(n-1)))*A[s-1];
        }

        double sumScores = 0.0;
        for (int i = 0; i < n; i++){
            sumScores += score[i];
        }

        for (int i = 0; i < n; i++){
            exp[i] = C*score[i]*H[S] + C*(sumScores-score[i])*A[S]/(n-1);
            exp[i] /= C;
        }
        return exp;
    }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, int p2, bool hasAnswer, vector <double> p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << p2;
	cout << "]" << endl;
	CandyBox *obj;
	vector <double> answer;
	obj = new CandyBox();
	clock_t startTime = clock();
	answer = obj->expectedScore(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p3.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p3[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p3.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (fabs(p3[i] - answer[i]) > 1e-9 * max(1.0, fabs(p3[i]))) {
					res = false;
				}
			}
		}
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	vector <int> p1;
	int p2;
	vector <double> p3;
	
	{
	// ----- test 0 -----
	p0 = 10;
	int t1[] = {1,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	double t3[] = {1.0,10.0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	int t1[] = {1,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	double t3[] = {4.0,7.000000000000001};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	int t1[] = {1,4,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	double t3[] = {5.0,5.0,5.0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 98;
	int t1[] = {13,82,74,78,12,71,81,80,30};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 154;
	double t3[] = {26.25622829378155,74.87969915903301,69.24219529059805,72.06094722481552,25.551540310227182,67.12813133993495,74.17501117547864,73.47032319192427,38.23592401420582};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!