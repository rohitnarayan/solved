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

// problem restatement: choose (xi,yi) cookies of color i
// such that P1*xi + P2*yi <= cookies[i]
// and such that sum xi = sum yi = S and (xi+yi) <= S for all i
// maximize P1*(sum xi) + P2*(sum yi) = (P1+P2)*S
// i.e. we have to maximize S

// if we  S
// maximize sum_xi given sum yi = S, alongwith (xi+yi) <= S

const int N = 55, M = 1010;
int DP[N][M];

// complexity logM * N * M * 40
// ~ 10 * 50 * 1000 * 40 = 2e7

class ColorfulCookie {
public:
    template <typename T>
    void maxout(T& a, T b){
        a = max(a,b);
    }

    vector <int> cookies;
    int P1, P2;

    // DP[i][Y] = maximum sum_xi considering cookies[0..i] and with sum_yi = Y

    bool possible(int S){
        memset(DP,-1,sizeof(DP));
        
        // find DP[0] 
        for (int y0 = 0; y0 <= cookies[0]/P2; y0++){
            DP[0][y0] = min((cookies[0] - y0*P2)/P1, S-y0);
        }

        int n = cookies.size();

        // Iterate through all valid DP[i-1] states to find DP[i] 
        for (int i = 1; i < n; i++){
            for (int z = 0; z < M; z++){
                if(DP[i-1][z] < 0)
                    continue;
                for (int y = 0; y <= cookies[i]/P2; y++){
                    int x = min((cookies[i]-y*P2)/P1, S-y);
                    if(y+z >= M)
                        break;
                    maxout(DP[i][y+z], DP[i-1][z] + x);
                }
            }
        }

        // S is attainable iff DP[n-1][S] >= S
        return DP[n-1][S] >= S;
    }

    int getMaximum(vector <int> _cookies, int _P1, int _P2) {
        cookies = _cookies;
        P1 = _P1, P2 = _P2;

        // binary search for the maximum attainable S
        int lo = 0, hi = 1001; // solution \in [lo,hi)
        while(hi - lo > 1){
            int m = (lo+hi)/2;
            if(possible(m))
                lo = m;
            else
                hi = m;
        }
        return lo*(P1+P2);

    }
};



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1 << "," << p2;
	cout << "]" << endl;
	ColorfulCookie *obj;
	int answer;
	obj = new ColorfulCookie();
	clock_t startTime = clock();
	answer = obj->getMaximum(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	
	vector <int> p0;
	int p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
        int t0[] = {10,10,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 9;
	p3 = 30;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {50,250,50};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 50;
	p2 = 100;
	p3 = 300;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {2000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100;
	p2 = 200;
	p3 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {123,456,789,555};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 58;
	p2 = 158;
	p3 = 1728;
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
