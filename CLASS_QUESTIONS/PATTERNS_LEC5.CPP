#include <iostream>
using namespace std;

int inputn (int k){
    cout << "Enter the number of rows ";
    cin >> k;
    return k;
}

int main() {
    
    // Printing patterns based on user input for rows and columns
   /*
    int a, b;
     cout << "Enter the number of rows ";
    cin >> a ;
    cout << "Enter the number of columns ";
    cin >> b ;
    cout << endl;
    // printing solid rectangle
    
    for(int row=0; row<a; row=row+1) {
        for(int col=0; col<b; col=col+1) {
            cout << "* ";
        }
        cout << endl;
    } 


    // printing hollow rectangle
    for(int row=0; row < a; row=row+1) {
       if (row==0 || row== a-1) {
            for(int col=0; col< b; col=col+1) {
                cout << "* ";
            }
        } else {
            for(int col=0; col< b; col=col+1) {
                if(col==0 || col== b-1) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
    */
    
    int n = inputn(0);
    /* 
    // printing half pyramid
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<row+1; col=col+1) {
            cout << "* ";
        }
        cout << endl;
    }
    */

    /*
    // printing inverted half pyramid
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<n-row; col=col+1) {
            cout << "* ";
        }
        cout << endl;
    }
    */
   
    /*
    // printing half pyramid with numbers
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<row+1; col=col+1) {
            cout << col+1;
        }
        cout << endl;
    }

    // printing inverted half pyramid with numbers
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<n-row; col=col+1) {
            cout << col+1;
        }
        cout << endl;
    }

    // hollow half inverted pyramid
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<n-row; col=col+1) {
            if(col==0 || col==n-row-1 || row==0) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    // full pyramid
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<n-row-1; col=col+1) {
            cout << "  ";
        }
        for(int col=0; col<2*row+1; col=col+1) {
            cout << "* ";
        }
        cout << endl;
    }

    // inverted full pyramid
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<row; col=col+1) {
            cout << "  ";
        }
        for(int col=0; col<2*(n-row)-1; col=col+1) {
            cout << "* ";
        }
        cout << endl;
    }

    // hollow full pyramid
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<n-row-1; col=col+1) {
            cout << "  ";
        }
        for(int col=0; col<2*row+1; col=col+1) {
            if(col==0 || col==2*row || row==n-1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
*/
  
 /* // diamond pattern
    
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<n-row-1; col=col+1) {
            cout << "  ";
        }
        for(int col=0; col<2*row+1; col=col+1) {
            cout << "* ";
        }
        cout << endl;
    }
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<row; col=col+1) {
            cout << "  ";
        }
        for(int col=0; col<2*(n-row)-1; col=col+1) {
            cout << "* ";
        }
        cout << endl;
    }

    // hollow diamond pattern
     // spaces
     for(int row=0; row<n; row=row+1) {
        for(int col=0; col<n-row-1; col=col+1) {
            cout << "  ";
        }
        // khali triangle
        for(int col=0; col<2*row+1; col=col+1) {
            if(col==0 || col==2*row || row==n-1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
     // inverted triangle
     for(int row=0; row<n; row=row+1){
        // spaces
        for(int col=0; col<row; col=col+1) {
            cout << "  ";
        }
     }
     //stars
        for(int col=0; col<2*(n-row)-1; col=col+1) {
            if(col==0 || col==2*(n-row)-2 || row==0) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;

    }

    // flipped diamond pattern
    
    // upper part
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<n-row-1; col=col+1) {
            cout << "  ";
        }
        for(int col=0; col<2*row+1; col=col+1) {
            cout << "* ";
        }
        cout << endl;
    }
    // lower part
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<row; col=col+1) {
            cout << "  ";
        }
        for(int col=0; col<2*(n-row)-1; col=col+1) {
            cout << "* ";
        }
        cout << endl;
    }
*/
/*
    //fancy pattern 
    // 1st half
    for(int row=0; row<n; row=row+1){
        
        for (int col=0; col<row+1; col =col+1){
            cout << row+1;
            if(col != row) {
                cout << "*";
            } 
        }
        cout << endl;
    }
    // 2nd half
    for(int row=0; row<n-1; row=row+1){
        for (int col=0; col<n-row; col =col+1){
            cout << n-row;
            if(col != n-row-1) {
                cout << "*";
            } 
        }
        cout << endl;
    }

 // alphabet palindrome pattern
    for(int row=0; row<n; row=row+1) {
        int col;
        for( col=0; col<row+1; col=col+1) {
            int ans = col + 1;
            char ch = ans + 'A' -1;
            cout << ch;
        }

        // reverse counting
        for( col=row; col>=1; col=col-1) {
            int ans = col + 1;
            char ch = ans + 'A' -1;
            cout << ch;
        }
        cout << endl;
    }

    // numeric full pyramid
    for(int row=0; row<n; row=row+1) {
        // spaces
        for(int col=0; col<n-row-1; col=col+1){
            cout << "  ";
        }
        //numbers
        for(int col=0; col<2*row+1; col=col+1) {
            cout << row + col + 1;
        }
        //reverse counting numbers
        int start = 2 * row;
        for(int col=0; col<row; col=col-1) {
            cout << start;
            start = start + 1;
        }
        cout << endl;
    }
*/

}