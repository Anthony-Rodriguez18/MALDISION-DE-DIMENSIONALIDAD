#include <iostream>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

struct punto
{
    int dim;
    vector<float> cordenadas;
    punto(int d)
    {
        dim = d;
        for (int j = 0; j < dim; j++)
        {
            random_device rd;
            mt19937 gen(rd());
            uniform_real_distribution<> dist(0, 1);
            cordenadas.push_back(dist(gen));
        }
    }

    void print()
    {
        for (int i = 0; i < cordenadas.size(); i++)
        {
            cout << cordenadas[i] << " ";
        }
    }
};

float disteucl(punto& a, punto& b)
{
    float d = 0.0;
    for (int i = 0; i < a.dim; i++)
    {
        d += pow(a.cordenadas[i] - b.cordenadas[i], 2);
    }
    return sqrt(d);
}

void crea_puntos(int d, int n, vector<punto>& a)
{
    for (int i = 0; i < n; i++) {
        punto punto(d);
        a.push_back(punto);
    }
}

void dist_total(int n, vector<punto>& a, vector<float>& b, ofstream& outfile)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float distance = disteucl(a[i], a[j]);
            b.push_back(distance);
            outfile << distance << endl;
        }
    }
}

void print_puntos(int n, vector<punto>& a)
{
    for (int i = 0; i < n; i++) {
        cout << "punto " << i + 1 << ": " << endl;
        a[i].print(); cout << " ";
        cout << endl;
    }
}

void print_distecl(vector<float>& b,int n)
{
    for (int i = 1; i < n; i++) {
        cout << "distancia" << i << ": " << endl;
        cout << b[i - 1] << " ";
        cout << endl;
    }
}

int main() {
    int numpun=100;
    vector<punto> dim_10;
    vector<punto> dim_50;
    vector<punto> dim_100;
    vector<punto> dim_500;
    vector<punto> dim_1000;
    vector<punto> dim_2000;
    vector<punto> dim_5000;


    vector<float> dist_10;
    vector<float> dist_50;
    vector<float> dist_100;
    vector<float> dist_500;
    vector<float> dist_1000;
    vector<float> dist_2000;
    vector<float> dist_5000;

    ofstream outfile_10("distancias_dim_10.txt");
    ofstream outfile_50("distancias_dim_50.txt");
    ofstream outfile_100("distancias_dim_100.txt");
    ofstream outfile_500("distancias_dim_500.txt");
    ofstream outfile_1000("distancias_dim_1000.txt");
    ofstream outfile_2000("distancias_dim_2000.txt");
    ofstream outfile_5000("distancias_dim_5000.txt");

    crea_puntos(10, numpun, dim_10);
    crea_puntos(50, numpun, dim_50);
    crea_puntos(100, numpun, dim_100);
    crea_puntos(500, numpun, dim_500);
    crea_puntos(1000, numpun, dim_1000);
    crea_puntos(2000, numpun, dim_2000);
    crea_puntos(5000, numpun, dim_5000);

    dist_total(numpun, dim_10, dist_10, outfile_10);
    dist_total(numpun, dim_50, dist_50, outfile_50);
    dist_total(numpun, dim_100, dist_100, outfile_100);
    dist_total(numpun, dim_500, dist_500, outfile_500);
    dist_total(numpun, dim_1000, dist_1000, outfile_1000);
    dist_total(numpun, dim_2000, dist_2000, outfile_2000);
    dist_total(numpun, dim_5000, dist_5000, outfile_5000);

    outfile_10.close();
    outfile_50.close();
    outfile_100.close();
    outfile_500.close();
    outfile_1000.close();
    outfile_2000.close();
    outfile_5000.close();

    return 0;
}