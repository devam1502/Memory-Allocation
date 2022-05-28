#include <bits/stdc++.h>
using namespace std;


int maxindex(int hsize[],int nh)
{
    int temp=hsize[0];
    int tempindex=0;
    for(int j=0;j<nh;++j)
    {
        if(hsize[j]>temp)
        {
            temp=hsize[j];
            tempindex=j;
        }
    }
    return tempindex;
}
void first_fit(int psizef[],int npf,int hsizef[],int nhf)
{
    int np,nh;

    np=npf;
    nh=nhf;
    int psize[np],hsize[nh];
    for(int j=0;j<np;++j)
    {
        psize[j]=psizef[j];
    }
    for(int j=0;j<nh;++j)
    {
        hsize[j]=hsizef[j];
    }
    int arr[np+1][nh];
    int allocation[np];
    int sum=0;
    for(int i=0;i<np;++i)
    {
        allocation[i]=-1;
    }
    for(int i=0;i<np;++i)
    {
        for(int j=0;j<nh;++j)
        {
            arr[i][j]=hsize[j];
        }
        for(int j=0;j<nh;++j)
        {
            if(psize[i]<=hsize[j])
            {
                allocation[i]=j+1;
                hsize[j]=hsize[j]-psize[i];
                break;
            }
        }


    }
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                              FIRST FIT METHOD                                                      " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------";
    cout << "\nProcess No.  |  Process Size  |  Hole no.   |   Holes Structure  " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < np; i++)
    {
        cout << "   " << i+1 << "\t     | " << psize[i] << "\t      |";
        if (allocation[i] != -1)
        {
            cout << allocation[i] << "            | ";
            for(int j=0;j<nh;++j)
            {
                cout << "||" << arr[i][j];
            }
            cout << "||" << endl;
        }
        else
        {
            cout << "Not Allocated" << "| " ;
            for(int j=0;j<nh;++j)
            {
                cout << "||" << arr[i][j];
            }
            cout << "||" << endl;
        }
    }
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    for(int j=0;j<nh;++j)
    {
        arr[np][j]=arr[np-1][j];
    }
    if(allocation[np-1]!=-1)
    {
        arr[np][allocation[np-1]-1]=arr[np-1][allocation[np-1]-1]-psize[np-1];
    }
    cout << "\nFinal Holes Structure : ";
    for(int j=0;j<nh;++j)
    {
        cout << "||" << arr[np][j];
    }
    cout << "||" << endl;
    cout << "\nTotal Remaining Holes Size : ";
    for(int j=0;j<nh;++j)
    {
        sum=sum+arr[np][j];
    }
    cout << sum << endl;
    cout << endl;
}
void next_fit(int psizen[],int npn,int hsizen[],int nhn)
{
    int np,nh;

    np=npn;
    nh=nhn;
    int psize[np],hsize[nh];
    for(int j=0;j<np;++j)
    {
        psize[j]=psizen[j];
    }
    for(int j=0;j<nh;++j)
    {
        hsize[j]=hsizen[j];
    }
    int arr[np+1][nh];
    int allocation[np];
    int temp=0,sum=0;
    for(int i=0;i<np;++i)
    {
        allocation[i]=-1;
    }
    for(int i=0;i<np;++i)
    {
        for(int j=0;j<nh;++j)
        {
            arr[i][j]=hsize[j];
        }
        for(int j=temp;j<nh;++j)
        {
            if(psize[i]<=hsize[j])
            {
                temp=j;
                allocation[i]=j+1;
                hsize[j]=hsize[j]-psize[i];
                break;
            }
        }

    }
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                               NEXT FIT METHOD                                                      " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------";
    cout << "\nProcess No.  |  Process Size  |  Hole no.   |   Holes Structure  " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < np; i++)
    {
        cout << "   " << i+1 << "\t     | " << psize[i] << "\t      |";
        if (allocation[i] != -1)
        {
            cout << allocation[i] << "            | ";
            for(int j=0;j<nh;++j)
            {
                cout << "||" << arr[i][j];
            }
            cout << "||" << endl;
        }
        else
        {
            cout << "Not Allocated" << "| " ;
            for(int j=0;j<nh;++j)
            {
                cout << "||" << arr[i][j];
            }
            cout << "||" << endl;
        }
    }
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    for(int j=0;j<nh;++j)
    {
        arr[np][j]=arr[np-1][j];
    }
    if(allocation[np-1]!=-1)
    {
        arr[np][allocation[np-1]-1]=arr[np-1][allocation[np-1]-1]-psize[np-1];
    }
    cout << "\nFinal Holes Structure : ";
    for(int j=0;j<nh;++j)
    {
        cout << "||" << arr[np][j];
    }
    cout << "||" << endl;
    cout << "\nTotal Remaining Holes Size : ";
    for(int j=0;j<nh;++j)
    {
        sum=sum+hsize[j];
    }
    cout << sum << endl;
    cout << endl;
}
void best_fit(int psizeb[],int npb,int hsizeb[],int nhb)
{
    int np,nh;

    np=npb;
    nh=nhb;
    int psize[np],hsize[nh];
    for(int j=0;j<np;++j)
    {
        psize[j]=psizeb[j];
    }
    for(int j=0;j<nh;++j)
    {
        hsize[j]=hsizeb[j];
    }
    int arr[np+1][nh];
    int allocation[np];
    int best_hole,best_index=-1,sum=0;
    for(int i=0;i<np;++i)
    {
        allocation[i]=-1;
    }

    for(int i=0;i<np;++i)
    {
        for(int j=0;j<nh;++j)
        {
            arr[i][j]=hsize[j];
        }
        vector<int>vect;
        for(int j=0;j<nh;++j)
        {
            if(hsize[j]>=psize[i])
            {
                vect.push_back(hsize[j]);
            }
        }
        if(vect.size()>0)
        {
            best_hole=*min_element(vect.begin(),vect.end());
            for(int j=0;j<nh;++j)
            {
                if(hsize[j]==best_hole)
                {
                    best_index=j;
                }
            }
            hsize[best_index]=hsize[best_index]-psize[i];
            allocation[i]=best_index+1;
        }
        vect.clear();

    }
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                               BEST FIT METHOD                                                      " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------";
    cout << "\nProcess No.  |  Process Size  |  Hole no.   |   Holes Structure  " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < np; i++)
    {
        cout << "   " << i+1 << "\t     | " << psize[i] << "\t      |";
        if (allocation[i] != -1)
        {
            cout << allocation[i] << "            | ";
            for(int j=0;j<nh;++j)
            {
                cout << "||" << arr[i][j];
            }
            cout << "||" << endl;
        }
        else
        {
            cout << "Not Allocated" << "| " ;
            for(int j=0;j<nh;++j)
            {
                cout << "||" << arr[i][j];
            }
            cout << "||" << endl;
        }
    }
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    for(int j=0;j<nh;++j)
    {
        arr[np][j]=arr[np-1][j];
    }
    if(allocation[np-1]!=-1)
    {
        arr[np][allocation[np-1]-1]=arr[np-1][allocation[np-1]-1]-psize[np-1];
    }
    cout << "\nFinal Holes Structure : ";
    for(int j=0;j<nh;++j)
    {
        cout << "||" << arr[np][j];
    }
    cout << "||" << endl;
    cout << "\nTotal Remaining Holes Size : ";
    for(int j=0;j<nh;++j)
    {
        sum=sum+arr[np][j];
    }
    cout << sum << endl;
    cout << endl;
}
void worst_fit(int psizew[],int npw,int hsizew[],int nhw)
{
    int np,nh;

    np=npw;
    nh=nhw;
    int psize[np],hsize[nh];
    for(int j=0;j<np;++j)
    {
        psize[j]=psizew[j];
    }
    for(int j=0;j<nh;++j)
    {
        hsize[j]=hsizew[j];
    }
    int arr[np+1][nh];
    int maxhole,sum=0;
    int allocation[np];
    for(int i=0;i<np;++i)
    {
        allocation[i]=-1;
    }
    for(int i=0;i<np;++i)
    {
        for(int j=0;j<nh;++j)
        {
            arr[i][j]=hsize[j];
        }
        maxhole=maxindex(hsize,nh);
        //cout<<hsize[maxhole]<<endl;
        if(psize[i]<=hsize[maxhole])
        {
            allocation[i]=maxhole+1;
            hsize[maxhole]=hsize[maxhole]-psize[i];
        }
        /*for(int j=0;j<nh;++j)
        {
            cout << arr[i][j] << " " ;
        }
        cout << endl;*/
    }
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                              WORST FIT METHOD                                                      " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------";
    cout << "\nProcess No.  |  Process Size  |  Hole no.   |   Holes Structure  " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < np; i++)
    {
        cout << "   " << i+1 << "\t     | " << psize[i] << "\t      |";
        if (allocation[i] != -1)
        {
            cout << allocation[i] << "            | ";
            for(int j=0;j<nh;++j)
            {
                cout << "||" << arr[i][j];
            }
            cout << "||" << endl;
        }
        else
        {
            cout << "Not Allocated" << "| " ;
            for(int j=0;j<nh;++j)
            {
                cout << "||" << arr[i][j];
            }
            cout << "||" << endl;
        }
    }
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    for(int j=0;j<nh;++j)
    {
        arr[np][j]=arr[np-1][j];
    }
    if(allocation[np-1]!=-1)
    {
        arr[np][allocation[np-1]-1]=arr[np-1][allocation[np-1]-1]-psize[np-1];
    }
    cout << "\nFinal Holes Structure : ";
    for(int j=0;j<nh;++j)
    {
        cout << "||" << arr[np][j];
    }
    cout << "||" << endl;
    cout << "\nTotal Remaining Holes Size : ";
    for(int j=0;j<nh;++j)
    {
        sum=sum+arr[np][j];
    }
    cout << sum << endl;
    cout << endl;
}
int main()
{
    int np,nh;
    cout << "                                                      Welcome User                             " << endl;
    cout << "                                                    Memory Allocation                          " << endl;
    cout << "> Enter the no. of processes   : ";
    cin >> np;
    int psize[np];
    cout << "> Enter the no. of holes       : ";
    cin >> nh;
    int hsize[nh];
    cout << "> Enter sizes of the processes : ";
    for(int i=0;i<np;++i)
    {
        cin >> psize[i];
        //psizef[i]=psizen[i]=psizeb[i]=psizew[i]=psize[i];

    }
    cout << "> Enter sizes of the holes     : ";
    for(int i=0;i<nh;++i)
    {
        cin >> hsize[i];
        //hsizef[i]=hsizen[i]=hsizeb[i]=hsizew[i]=hsize[i];
    }
    int num=1;
    while(num!=0)
    {
        cout << "------------------" << endl;
        cout << "      Choices     " << endl;
        cout << "------------------" << endl;
        cout << "  First Fit -> 1" << endl;
        cout << "  Next Fit -> 2" << endl;
        cout << "  Best Fit -> 3" << endl;
        cout << "  Worst Fit -> 4" << endl;
        cout << "  Exit -> 0" << endl;
        cout << "> Enter your choice for type of memory allocation : " ;

        cin >> num;
        switch (num)
        {
        case 1:
            first_fit(psize,np,hsize,nh);
            break;
        case 2:
            next_fit(psize,np,hsize,nh);
            break;
        case 3:
            best_fit(psize,np,hsize,nh);
            break;
        case 4:
            worst_fit(psize,np,hsize,nh);
            break;
        case 0:
            break;
        default:
            cout << "Enter valid choice number!!!!" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
            break;
        }
    }
    return 0;
}
