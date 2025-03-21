/*
 Matthew Winer
 CMPR 131
 March 16 2025
 HW1
 */

#include <iostream>
#include "DArray.h"
#include <string>

using namespace std;

void displayMenu() {
    cout << "\nPlaylist Manager\n";
    cout << "1. Add a song\n";
    cout << "2. View playlist\n";
    cout << "3. Search for a song\n";
    cout << "4. Remove a song\n";
    cout << "5. Check if playlist is sorted\n";
    cout << "6. Compare two playlists\n";
    cout << "7. Merge two playlists\n";
    cout << "8. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    DArray playlist;  // Default 50 capacity
    DArray anotherPlaylist;
    int choice;
    string song;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();  // Ignore newline character
        
        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin, song);
                playlist.addElement(song);
                break;

            case 2:
                cout << "\nPlaylist:\n" << playlist << endl;
                break;
            
            case 3:
                cout << "Enter song to search for: ";
                getline(cin, song);
                if (playlist.findElement(song) != -1)
                    cout << "Song found!" << endl;
                else
                    cout << "Song not found." << endl;
                break;

            case 4:
                cout << "Enter song to remove: ";
                getline(cin, song);
                if (playlist.removeElement(song))
                    cout << "Song removed." << endl;
                else
                    cout << "Song not found." << endl;
                break;

            case 5:
                cout << (playlist.isSorted() ? "Playlist is sorted." : "Playlist is NOT sorted.") << endl;
                break;

            case 6:
                cout << "Comparing with another empty playlist..." << endl;
                cout << (playlist.compareArrays(anotherPlaylist) ? "Playlists are identical." : "Playlists are different.") << endl;
                break;

            case 7:
                cout << "Merging playlists..." << endl;
                playlist += anotherPlaylist;
                cout << "Playlists merged successfully." << endl;
                break;

            case 8:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 8);
    
    return 0;
}
