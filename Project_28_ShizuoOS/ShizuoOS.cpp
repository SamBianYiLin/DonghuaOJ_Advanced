#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct File
{
	string FileName;
	short FileType;
	string FileInfo;
	File(string _FileName,short _FileType,string _FileInfo) {
		FileName = _FileName;
		FileType = _FileType;
		FileInfo = _FileInfo;
	}
};
vector<File> FileSystem;
void FileOpen(string openFileName,int pos) {
	while ( FileSystem[pos].FileName == openFileName &&
		FileSystem[pos].FileType == 1) {
		for (int i = 0; i < FileSystem.size(); i++)	{
			if (FileSystem[i].FileName == FileSystem[pos].FileInfo) {
				FileOpen(FileSystem[pos].FileInfo, i);
				return;
			}		
		}
	}
	if (FileSystem[pos].FileType == 0 &&
		FileSystem[pos].FileName == openFileName) {
		printf("%s\n", FileSystem[pos].FileInfo.c_str());
		return;
	}
}
int main() {
	char c[100];	
	while (fgets(c,100,stdin)) {
		string command = c;
		if (command[command.size() - 1] == '\n') command.erase(command.size() - 1, 1);
		if (command == "exit") {
			return 0;
		}	
		string fileOP = "", openFile = "";
		string fileName = "", fileInfo = "";
		short fileType = 0; string temp = "";
		int space_counter = 0;
		for (int i = 0; i <= command.size(); i++) {
			if (command[i] == ' ' && space_counter == 0) {
				fileOP = temp;
				space_counter++;
				temp = "";
			}
			else if (command[i] == ' ' && space_counter == 1) {
				fileName = temp;
				space_counter++;
				temp = "";
			}
			else if (command[i] == ' ' && space_counter == 2) {
				fileType =  stoi(temp);
				space_counter++;
				temp = "";
			}
			else if (fileOP != "open" && i == command.size()) {
				fileInfo = temp;
			}
			else if (fileOP == "open" && i == command.size()) {
				openFile = temp;
			}
			else temp += command[i];
		}
		//	printf("%s %s %d %s\n",fileOP.c_str(), fileName.c_str(), fileType, fileInfo.c_str());
		//	printf("%s %s\n", fileOP.c_str(), openFile.c_str());
		if (fileOP == "create") {
			bool fileAlreadyExist = false;
			for (int i = 0; i < FileSystem.size(); i++) {
				if (FileSystem[i].FileName == fileName) {
					//	更新文件信息
					FileSystem[i].FileType = fileType;
					FileSystem[i].FileInfo = fileInfo;
					fileAlreadyExist = true;
					break;
				}
			}
			if (!fileAlreadyExist) {
				File file(fileName, fileType, fileInfo);
				FileSystem.push_back(file);
			}
		}
		else if (fileOP == "open") {
			for (int i = 0; i < FileSystem.size(); i++) {
				if (FileSystem[i].FileName == openFile) {
					FileOpen(openFile, i);
					break;
				}
			}
		}
	}

	return 0;
}