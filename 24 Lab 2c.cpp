#include<iostream>
#include<iomanip>
#include<stack>

using namespace std;

void tower(int disks, stack<int>& source, stack<int>& dest, stack<int>& inter);

int main()
{
	stack <int> source;
	source.push(3);
	source.push(2);
	source.push(1);

	stack <char> intermediate;
	stack <int> destination;

	tower(source.size(), source, destination, intermediate);

	cout << source << "\t" << intermediate.size() << "\t" << destination.size();

	return 0;
}

void tower(int disks, stack<int>& source, stack<int>& dest, stack<int>& inter)
{
	if (disks == 1)
	{
		dest.push(source.top());
		source.pop();
	}
	else
	{
		tower(disks - 1, source, inter, dest);
		dest.push(source.top());
		source.pop();
		tower(disks - 1, inter, dest, source);
	}
}