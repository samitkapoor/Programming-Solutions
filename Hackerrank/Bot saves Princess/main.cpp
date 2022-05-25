#include <iostream>
#include <vector>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here
    int blocks = (int)grid.size();
    
    int row = blocks/2;
    int col = blocks/2;
    
    if(grid[0][0] == 'p'){
        for(int i = row ; i>0 ; i--){
            cout<<"UP"<<endl;
        }
        
        for(int i = col ; i>0 ; i--){
            cout<<"LEFT"<<endl;
        }
    }
    else if(grid[0][blocks-1] == 'p'){
        for(int i = row ; i>0 ; i--){
            cout<<"UP"<<endl;
        }
        
        for(int i = col; i<blocks-1 ; i++){
            cout<<"RIGHT"<<endl;
        }
    }
    else if(grid[blocks-1][0] == 'p'){
        for(int i = row ; i < blocks-1 ; i++){
            cout<<"DOWN"<<endl;
        }
        
        for(int i = col ; i>0 ; i--){
            cout<<"LEFT"<<endl;
        }
    }
    else{
        for(int i = row ; i < blocks-1 ; i++){
            cout<<"DOWN"<<endl;
        }
        
        for(int i = col ; i<blocks-1 ; i++){
            cout<<"RIGHT"<<endl;
        }
    }
}

int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}