#include <bits/stdc++.h>
#define threshold 3
using namespace std;
vector<int> seeksequence;
bool over_threshold(vector<int> &counter,vector<bool> &granted_request, int
&max_threshold)
{
bool flag=false;
for (int i=0;i<counter.size();i++)
{
if (granted_request[i]==false && counter[i] >= threshold)
{
flag=true;
max_threshold=max(max_threshold,counter[i]);
}
}
return flag;
}

void threshold_seek(vector<int> &requests, vector<int> &counter, vector<bool>
&granted_request, int &head, int &seekcount, int &max_threshold)
{
int min_seek = INT_MAX;
int min_seek_index = -1;
for (int i = 0; i < requests.size(); i++)
{
if (granted_request[i] == false && counter[i] == max_threshold)
{
min_seek = min(min_seek, abs(requests[i] - head));
if (min_seek == abs(requests[i] - head))
min_seek_index = i;
}
}
seekcount += min_seek;
head = requests[min_seek_index];
seeksequence.push_back(head);
granted_request[min_seek_index] = true;
for (int i = 0; i < requests.size(); i++)
{
if (granted_request[i] == false)
{
counter[i]++;
}
}
}
void normal_seek(vector<int> &requests, vector<int> &counter, vector<bool>
&granted_request, int &head, int &seekcount)
{
int min_seek = INT_MAX;
int min_seek_index = -1;
for (int i = 0; i < requests.size(); i++)
{
if (granted_request[i] == false)
{
min_seek = min(min_seek, abs(requests[i] - head));
if (min_seek == abs(requests[i] - head))
min_seek_index = i;
}

}
seekcount += min_seek;
head = requests[min_seek_index];
seeksequence.push_back(head);
granted_request[min_seek_index] = true;
for (int i = 0; i < requests.size(); i++)
{
if (granted_request[i] == false)
{
counter[i]++;
}
}
}
int main()
{
int head = 50;
int seekcount = 0;
vector<int> requests = {176, 79, 34, 60, 92, 11, 41, 114};
int n = requests.size();
vector<int> counter(n, 0);
vector<bool> granted_request(n, false);
int requests_processed = 0;
while (requests_processed != n)
{
int max_threshold=INT_MIN;
if (over_threshold(counter,granted_request,max_threshold))
{
threshold_seek(requests, counter, granted_request, head,
seekcount,max_threshold);
}
else
{
normal_seek(requests, counter, granted_request, head, seekcount);
}
requests_processed++;
cout << "Processed an existing request" << endl
<< "Add a new Request (y/n)?";
char a;

cin >> a;
if (a == 'y' || a == 'Y')
{
cout << "Request distance:";
int b;
cin >> b;
requests.push_back(b);
granted_request.push_back(false);
counter.push_back(0);
n = requests.size();
}
cout<<endl;
}
cout <<endl<< "Seek Sequence is: " << endl;
for (auto a : seeksequence)
{
cout << a << endl;
}
cout << endl
<< "Total number of seek operations is: " << seekcount << endl;
}