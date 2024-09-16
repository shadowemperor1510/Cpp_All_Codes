
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//defining helper functions

float distance(vector<int> vec1 , vector<int> vec2) {

    float distance = 0;

    for(int i = 0 ; i < vec1.size() ; i ++) {

        distance += pow( (vec1[i] - vec2[i]) , 2 );
    }

    distance = pow(distance , 0.5);

    return distance;

}

int traverse( int graph[][], int fuel , int start , vector<int> preferences) {

    int result = 0;

    for(int i = 0 ; i < fuel ; i++) { 

       result+=  preferences[start];

        pair<int , int> max_vertex;
        max_vertex.first = 0;

        for(int j =0 ; j < graph[0].size() ; j++ ) {

            if(graph[start][j] == 1) {

                if(preferences[j] > max_vertex.first) {

                    max_vertex.first = preferences[j];
                    max_vertex.second = j;
                }
            }

        }

        start = max_vertex.second;


    }

    return result;

}



// using adjacency matrix as the graph representation

float average(int tourists , vector < int> happiness[] ) {

    vector<float> val_store;
    for(int i = 0; i < tourists; i++){
        float value = 0;
        for(int j = i + 1; j < tourists; j++){
            value += distance(happiness[i], happiness[j]);
        }
        val_store[i] = value;
    }
    // distance(tourists)
    float sum=0;
    for(int i=0; i< tourists-1;i++){
        sum+=val_store[i];
    }
    float avg=sum/(tourists-1);

    // sort(val_store, val_store + tourists - 1);

    // float median = val_store[(tourists - 1) / 2];

    return avg;
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    vector<int> inputs;
    int v, e, f, n;

    cin >> v >> e>> f >> n;   // n is the number of passengers

    // vector< vector<int>(v ,0) > adj_matrix; 
    int adj_matrix[v][n];
    int c1 , c2;

    vector<int> perferences[n];

    for(int i =0 ; i < e; i++) {

        cin >> c1;
        cin >> c2;

        adj_matrix[c1][c2] = 1;
        adj_matrix[c2][c1] = 1;

    }


    vector<int> temp;

    for(int i =0 ; i < n ; i++) {

        for(int j = 0; j < v; j++) {

            cin >> temp[j];
        }

        perferences[i] = temp;

    }

    int max_score = 0 ;
    int max_index;

    for(int i =0 ; i < n ; i++) {

        pair< int , int > max_vertex;
        max_vertex.first = 0;

        for(int j =0 ; j < v; j++) {

            if(perferences[i][j] > max_vertex.first) {

                max_vertex.first = perferences[i][j];
                max_vertex.second = j;
            }

        }

        if ( traverse( adj_matrix, f , max_vertex.second ,  perferences[i]) > max_score) {

            max_score =  traverse( adj_matrix, f , max_vertex.second ,  perferences[i]);
            max_index = i;
        }


    }

    int pivot = max_index;

    float threshold = average(n , perferences);

    vector<int> final_list;

    for(int i = 0 ;  i < n ; i++) {

        if( distance(perferences[pivot] , perferences[i]) < threshold && i!=pivot) {

            final_list.push_back(i);

        }


    }

    vector<int> final_preferences;
    int temp_pre = 0;
    int max_val =  0;
    max_index = 0;

    for(int i = 0 ; i < v; i ++) {

        for(int j = 0 ; j < final_list.size(); j ++) {

            temp_pre+= perferences[final_list[j]][i];
        }

        final_preferences[i] = temp_pre;

        if(final_preferences[i] > max_val) {

            max_val = final_preferences[i];
            max_index = i;
        }

        temp_pre = 0;
    }

   return traverse(adj_matrix , f , max_index , final_preferences);

}