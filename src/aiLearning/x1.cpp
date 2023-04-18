#include <iostream>
#include <vector>

using namespace std;

class LinearRegression {
public:
    LinearRegression(double alpha = 0.01, int iterations = 1000) : alpha(alpha), iterations(iterations) {}

    void fit(const vector<vector<double> >& X, const vector<double>& y) {
        int m = X.size();
        int n = X[0].size();
        theta.resize(n);
        for (int i = 0; i < iterations; ++i) {
            vector<double> h(m);
            for (int j = 0; j < m; ++j) {
                h[j] = predict(X[j]);
            }
            for (int j = 0; j < n; ++j) {
                double gradient = 0;
                for (int k = 0; k < m; ++k) {
                    gradient += (h[k] - y[k]) * X[k][j];
                }
                theta[j] -= alpha * gradient / m;
            }
        }
    }

    double predict(const vector<double>& x) {
        double result = 0;
        for (int i = 0; i < x.size(); ++i) {
            result += x[i] * theta[i];
        }
        return result;
    }

private:
    double alpha;
    int iterations;
    vector<double> theta;
};

int main() {
    vector<vector<double> > X{{1, 1}, {1, 2}, {1, 3}};
    vector<double> y{1, 2, 3};
    LinearRegression lr;
    lr.fit(X, y);
    cout << lr.predict({1, 4}) << endl;
    return 0;
}
//定义了一个`LinearRegression`类，它有两个公共方法：`fit`和`predict`。`fit`方法用来拟合线性方程，`predict`方法用来预测新数据的结果。