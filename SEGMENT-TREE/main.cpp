#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

int n = 8;
int size = (n * 2);
vector<int> arr(size,0);

int rndm() { return rand() % 10; }

// ==================== RANGE QUERY ====================

int RQ(int i, int f, int pos, int x, int y)
{
  	if (i > f)
    	return 0;
  	if (i == x && f == y)
    	return arr[pos];
  	if (f < x || i > y)
	  	return 0;
    int m = (x + y) / 2;
  	return 	RQ(i,m,pos*2,x,m) + 
         	RQ(m+1,f,(pos*2)+1,m+1,y);
}

int range_query(int i, int f)
{
	return RQ(i,f,1,1,n);
}

// ==================== BUILD TREE ====================

void build(int i)
{
	while(i != 0)
	{
		arr[i/2]=arr[i]+ arr[i+1];
		i-=2;    
	}
}

// ====================== UPDATE ======================
void update(int val, int pos)
{
	int dif = val - arr[pos];
	while (pos != 0)
	{
		arr[pos] += dif;
		pos /= 2;
	}
}

// ====================== PRINT ======================
int getHeight()
{
	int output = 0;
	for (int i = size; i != 0; i /= 2)
		output++;
	return output - 1;
}

int two_pow_to(int h)
{
    if (h == 0)
        return 1;
    return 1 << h;
}

void print()
{
    int H = getHeight();
    
    // Imprimir la lista en el documento
    int k = (1 << H) - 1;
    int c = 1;
    string space(3*k, ' ');
    cout << space;
    printf("%03d\n", arr[c]);
	cout << space << " | " << endl;
    int h = H - 1;
	bool space_line = 1;
    for (int i = 2; i < (1 << H); i<<=1)
    {
        k = two_pow_to(h) - 1;
        h--;
        for (int j = 0; j < i; j++)
        {
            string space(3*k, ' ');
			string line(3*k, '-');
			if (space_line)
			{
				cout << space;
	            printf("%03d", arr[++c]);
	            cout << line;
				cout << "-+-";
			}
			else
			{
				cout << line;
	            printf("%03d", arr[++c]);
	            cout << space;
				cout << "   ";
			}
            space_line = !space_line;
        }
        cout << endl;
		if (i < (1 << (H-1)))
		{
			for (int j = 0; j < i; j++)
			{
				string space(3*k, ' ');
				cout << space;
				cout << " | ";
				cout << space;
				cout << "   ";
			}
			cout << endl;
		}
    }
	
}

int main()
{
  	srand(time(NULL));
  	cout << "ORIGINAL: ";
	for (int i = size - n; i < arr.size(); i++)
	{
		arr[i] = rndm();
		cout << arr[i] << " ";
	}
	cout << endl;
	
  	build(size-2);
	
	cout << "SEGMENT TREE: ";
	for (int i = 1; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	int i = 2;
	int j = 6;
	cout << "RANGE QUERY (" << i << "," << j << "): ";
	cout << range_query(i, j) << endl;
	print();
}
