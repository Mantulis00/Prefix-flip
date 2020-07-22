#include <iostream>
#include <vector>
#include <string>

using namespace std;


/// change first or change all from the end <-
/// example -> start w/ 1 2 3 4 5 6
/// you trying to fill 6th slot, u check if b[6] and a[6] is same if its you live how it is
/// if its not same you check if you need to alter 1 that after reverse it'd be b[6] == a[1]
/// if it needs to be changed just add 1 to alter vector
/// then just reverse everything and delete first slot, it becomes 6 5 4 3 2 1, where 1 is
/// solid and values are reversed, so from++ (dont touch first value anymore)
/// then again repeat
/// algorithm difficulty O(n*(m+m+2m)) = O(4nm)


int main()
{
    long n, m;
    bool a[100010], b[100010];
    bool reversed;
    long from, to;

    vector<long> coms;
    string sa, sb;


cin >> n;
for (long x=0; x<n; x++)
{
        cin >> m;
        coms.clear();

        cin >> sa >> sb;

        for (long x=0; x<m; x++)
        {
            if (sa[x] == '1') a[x] = true;
            else a[x] = false;
            if (sb[x] == '1') b[x] = true;
            else b[x] = false;
        }


        from = 0;
        to = m-1;
        reversed = false;


        for (long x=m-1; x>=0; x--)
        {
          if (reversed)
          {
              if (a[from] != b[x]) // to (zero position) // from pre-end posision
              {
                  from++;
              }
              else
              {
                //  cout << "XD2";
                  if (a[to] != b[x])
                    coms.push_back(1);
                 if (x!=0 || (x == 0 && a[to] == b[x]))
                    coms.push_back(x+1);

                  to--;
                  reversed = false;


              }
          }
          else
          {
              if (a[to] == b[x]) // from (zero position)
              {
                  to--;

              }
              else
              {
                  //cout << "XD1";
                  if (a[from] == b[x])
                    coms.push_back(1);
                 if (x!=0 || (x == 0 && a[from] != b[x]))
                    coms.push_back(x+1);

                  from++;
                  reversed = true;

              }
          }
        }

        cout << coms.size() << " ";
    for (long x=0; x<coms.size();x++)
    {
        cout << coms[x] << " ";
    }
    cout << endl;
}




    return 0;
}
