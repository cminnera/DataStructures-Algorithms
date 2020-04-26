//Clare
//Lab 7 part 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
#include <cmath> 
#define pi 3.14159265358979323846
using namespace std;

class node
{
public:
	string place;
	double latitude, longitude;	//location
	node *nw, *ne, *sw, *se;	//pointers
	double getLatitude()
	{
		return latitude;
	}
	double getLongitude()
	{
		return longitude;
	}
	string getPlace()
	{
		return place;
	}
	
};

class quadtree
{
public:
	node root;
	double avgnode;
	vector<double> run;
	bool addNode(node& l)
	{
		if (root.latitude == 0 && root.longitude == 0)
		{
			root = l;
			return true;
		}
		else
		{
			return insert(l, root);
		}
	}
	bool insert(node& l, node &r)
	{
		if (l.latitude >= r.latitude&&l.longitude >= r.longitude)
		{
			if (r.ne == nullptr)
			{
				r.ne = &l;
				return true;
			}
			else
				insert(l, *r.ne);
		}
		else if (l.latitude >= r.latitude&&l.longitude <= r.longitude)
		{
			if (r.nw == nullptr)
			{
				r.nw = &l;
				return true;
			}
			else
				insert(l, *r.nw);
		}
		else if (l.latitude <= r.latitude&&l.longitude >= r.longitude)
		{
			if (r.se == nullptr)
			{
				r.se = &l;
				return true;
			}
			else
				insert(l, *r.se);
		}
		else if (l.latitude <= r.latitude&&l.longitude <= r.longitude)
		{
			if (r.sw == nullptr)
			{
				r.sw = &l;
				return true;
			}
			else
				insert(l, *r.sw);
		}
		else
			return false;
	}



	// This function converts decimal degrees to radians
	double deg2rad(double deg) {
		return (deg * pi / 180);
	};

	//  This function converts radians to decimal degrees
	double rad2deg(double rad) {
		return (rad * 180 / pi);
	};

	void findPlaces(double lat, double lon, int d, node tmp, int count = 0, int cnodes = 0)
	{
		double dis;
		double lat2, lon2;
		lat = deg2rad(lat);
		lon = deg2rad(lon);

		if (cnodes <= 2)
		{
			cout << tmp.place << endl;
		}

		lat2 = deg2rad(tmp.latitude);
		lon2 = deg2rad(tmp.longitude);
		dis = 3965 * acos(sin(lat)*sin(lat2) + cos(lat)*cos(lat2)*cos(lon2 - lon));
		if (dis <= d)
		{
			count++;
			cnodes++;
			cout << setw(18) << tmp.place;
			if(count % 3 == 0 && count != 0)
				cout << endl;
			if (tmp.ne != nullptr)
				findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.ne, count, cnodes);
			if (tmp.nw!=nullptr)
				findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.nw, count, cnodes);
			if (tmp.se!=nullptr)
				findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.se, count, cnodes);
			if (tmp.sw!=nullptr)
				findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.sw, count, cnodes);
		}
		else
		{
			cnodes++;
			if (rad2deg(lat2) <= rad2deg(lat) && rad2deg(lon2) >= rad2deg(lon))
			{
				if (tmp.ne != nullptr)
					findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.ne, count, cnodes);
				if (tmp.nw != nullptr)
					findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.nw, count, cnodes);
				if (tmp.sw != nullptr)
					findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.sw, count, cnodes);
			}
			else if (rad2deg(lat2) <= rad2deg(lat) && rad2deg(lon2) <= rad2deg(lon))
			{
				if (tmp.nw != nullptr)
					findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.nw, count, cnodes);
				if (tmp.se != nullptr)
					findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.se, count, cnodes);
				if (tmp.ne != nullptr)
					findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.ne, count, cnodes);
			}
			else if (rad2deg(lat2) >= rad2deg(lat) && rad2deg(lon2) >= rad2deg(lon))
			{
				if (tmp.sw != nullptr)
					findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.sw, count, cnodes);
				if (tmp.se != nullptr)
					findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.se, count, cnodes);
				if (tmp.nw != nullptr)
					findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.nw, count, cnodes);
			}
			else if (rad2deg(lat2) >= rad2deg(lat) && rad2deg(lon2) <= rad2deg(lon))
			{
				if (tmp.ne != nullptr)
					findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.ne, count, cnodes);
				if (tmp.sw != nullptr)
					findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.sw, count, cnodes);
				if (tmp.se != nullptr)
					findPlaces(rad2deg(lat), rad2deg(lon), d, *tmp.se, count, cnodes);
			}
		}
		}

	quadtree()
	{
		root.place = "";
		root.latitude = 0;
		root.longitude = 0;
		root.ne = nullptr;
		root.nw = nullptr;
		root.se = nullptr;
		root.sw = nullptr;
	}
};

void stateCities(string state, multimap<string, string> sTop)
{
	multimap<string, string>::iterator it;
	int count = 0;
	for (it = sTop.begin(); it != sTop.end(); it++)
	{
		if (it->first == state)
		{
			cout << setw(18) << it->second;
			count++;
		}
		if (count % 4 == 0 && count != 0)
			cout << endl;
	}
}

bool zipCity(string z, map<string, string> zToc)
{
	bool found = false;

	for each(auto pr in zToc)
	{
		if (z == pr.first)
		{
			found = true;
			cout << z << " is a zip code in " << pr.second << endl;
		}
	}
	return found;
}

bool placeToCord(string c, string s, map<string, pair<double, double>> pToL)
{
	bool found = false;
	for each(auto pr in pToL)
	{
		if (c + ", " + s == pr.first)
		{
			found = true;
			cout << c << ", " << s << " is at (" << pr.second.first << ", " << pr.second.second << ") \n";
		}
	}
	return found;
}

int main(void)
{
	map<string, string> ZipToPlace;
	map<string, pair<double, double>> PlaceToLocation;
	multimap<string, string> PlaceToStates;
	multimap<string, string> StateToPlaces;
	quadtree fourTree;
	bool first = true;
	int i;
	ifstream fin;
	const int n = 42741;
	try
	{
		string zip, slatitude, slongitude, city, state, country;
		double latitude, longitude;
		stringstream ss;
		fin.open("cities.txt");
		cout << "Reading data file...";
		for (i = 1; i <= 10; i++)
		{
			getline(fin, zip, ',');
			getline(fin, slatitude, ',');
			getline(fin, slongitude, ',');
			getline(fin, city, ',');
			getline(fin, state, ',');
			getline(fin, country, '\n');
			if (zip == "" || slatitude == "" || slongitude == "" || city == "" || state == "")
				continue;
			while (zip.length() < 5)
				zip = "0" + zip;
			ss.clear(); ss << slatitude; ss >> latitude;
			ss.clear(); ss << slongitude; ss >> longitude;


			ZipToPlace.insert(pair<string, string>(zip, city + ", " + state));
			
			
			if (!(PlaceToLocation.find(city + ", " + state) == PlaceToLocation.end()))
			{
				/*PlaceToLocation.insert(pair<string, pair<double, double>>(city + ", " + state, pair<double, double>(latitude, longitude)));
				PlaceToStates.insert(pair<string, string>(city, state));
				StateToPlaces.insert(pair<string, string>(state, city));
				node leaf;
				leaf.latitude = latitude;
				leaf.longitude = longitude;
				leaf.place = city + ", " + state;
				leaf.ne = nullptr;
				leaf.nw = nullptr;
				leaf.se = nullptr;
				leaf.sw = nullptr;

				fourTree.addNode(leaf);*/

			}
			else
			{
				PlaceToLocation.insert(pair<string, pair<double, double>>(city + ", " + state, pair<double, double>(latitude, longitude)));
				PlaceToStates.insert(pair<string, string>(city, state));
				StateToPlaces.insert(pair<string, string>(state, city));
				node leaf;
				leaf.latitude = latitude;
				leaf.longitude = longitude;
				leaf.place = city + ", " + state;
				leaf.ne = nullptr;
				leaf.nw = nullptr;
				leaf.se = nullptr;
				leaf.sw = nullptr;

				fourTree.addNode(leaf);
			}

		}
		cout << "Last line read was " << zip << "," << city << "," << state << " at ("
			<< latitude << "," << longitude << ")\n";
		cout << "done reading data file\n";
		fin.close();
	}
	catch (...)
	{
		cout << "Error reading from citites.txt\n";
		return 1;
	}

	bool TorF;
	char choice;
	string state1;
	string zipC;
	string city1;
	int distance;

	cout << "Z - find a place by zip code\n";
	cout << "L - show where a place is: i.e., its location\n";
	cout << "S - find cities by state (i.e., enter MA or Massachusetts)\n";
	cout << "D - find all places in the US within distance D of a given place\n";
	cout << "E - exit from the menu\n";

	do {
		cout << "Enter option: H(help), Z, L, S, D, or E: ";
		cin >> choice;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (toupper(choice))
		{
		case 'H':
			cout << "Z - find a place by zip code\n";
			cout << "L - show where a place is: i.e., its location\n";
			cout << "S - find cities by state (i.e., enter MA or Massachusetts)\n";
			cout << "D - find all places in the US within distance D of a given place\n";
			cout << "E - exit from the menu\n";
			break;
		case 'Z':
			cout << "Enter 5-digit zip code: ";
			cin >> zipC;
			if (zipC.length() < 5)
			{
				cout << "Incorrect Input\n";
				break;
			}
			TorF = zipCity(zipC, ZipToPlace);
			if (!TorF)
			{
				cout << "Not found\n";
			}
			break;
		case 'L':
			cout << "Enter the city: ";
			cin >> city1;
			cout << "Enter the state: ";
			cin >> state1;
			TorF = placeToCord(city1, state1, PlaceToLocation);
			if (!TorF)
			{
				cout << "Not found\n";
			}
			break;
		case 'S':
			cout << "Enter the state: ";
			cin >> state1;
			stateCities(state1, StateToPlaces);
			cout << endl;
			break;
		case 'D':
			cout << "Enter the city: ";
			cin >> city1;
			cout << "Enter the state: ";
			cin >> state1;
			TorF = placeToCord(city1, state1, PlaceToLocation);
			if (!TorF)
			{
				cout << "Not found\n";
			}
			cout << "Enter the distance: ";
			cin >> distance;
			fourTree.findPlaces(PlaceToLocation[city1 + ", " + state1].first, PlaceToLocation[city1 + ", " + state1].second, distance, fourTree.root);
			break;
		case 'E':
			cout << "Statistics: ";
			break;
		default:
			cout << "Invalid input. " << endl;
			break;
		}
	} while (choice != 'E' && choice != 'e');


	return 0;
}