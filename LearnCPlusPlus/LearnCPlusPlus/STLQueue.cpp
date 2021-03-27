#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define SIZE 5
void print(int array[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}

struct Cell {
	int row, col;
	vector<struct Cell> vistedList;
	Cell(int i, int j) {
		row = i;
		col = j;
	}
	Cell(int i, int j, vector<struct Cell> vistedIn) {
		row = i;
		col = j;
		vistedList = vistedIn;
		vistedList.push_back(Cell(row, col));
	}

};

void visit(queue<Cell>& q, Cell cell, int array[][SIZE]) {
	if (cell.row >= 0 && cell.row < SIZE &&
		cell.col >= 0 && cell.col < SIZE) {
		if (array[cell.row][cell.col] == 1) {
			q.push(cell);
			array[cell.row][cell.col] = -1;
		}
	}
}

int main24() {
	 
	int array[SIZE][SIZE] = {   {1,1,1,1,0},
								{1,1,0,0,0},
								{0,0,1,1,0},
								{1,1,0,1,0},
								{0,0,0,0,1} 
							};

	print(array);

	// Search BFS

	queue<Cell> q;
	Cell start(0, 0);
	Cell target(4, 4);
	vector<Cell> vec;
	visit(q, Cell(start.row, start.col , vec), array);

	while (!q.empty()) {

		Cell cell = q.front();

		if (cell.row == target.row && cell.col == target.col) {

			for (auto i = cell.vistedList.begin(); i != cell.vistedList.end(); i++) {
				Cell currentCell = (Cell)*i;
				cout << "("<<currentCell.row << "," << currentCell.col << ") -->";
			}
			cout << endl;
			break;
		}

		visit(q, Cell(cell.row+1,cell.col+1,cell.vistedList), array);
		visit(q, Cell(cell.row , cell.col+ 1, cell.vistedList), array);

		q.pop();
	}

	system("pause");
	return 0;
}