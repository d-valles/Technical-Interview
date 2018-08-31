function sudoku2(grid) {
    sectors = [
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map()
    ]

    columns = [
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map()
    ]

    lines = [
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map(),
        new Map()
    ]

    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            let sector = getSector(i, j)
            if (grid[i][j] != "."
                && (isNotValidLine(i, grid[i][j], lines)
                    || isNotValidColumn(j, grid[i][j], columns)
                    || isNotValidSector(sector, grid[i][j], sectors))) return false;
        }
    }

    return true;
}

function isNotValidLine(line, number, lines) {
    if (lines[line].has(number)) return true;
    lines[line].set(number);
    return false;
}

function getSector(i, j) {
    if (i < 3) {
        if (j < 3) {
            return 0;
        } else if (j < 6) {
            return 1;
        } else {
            return 2;
        }
    } else if (i < 6) {
        if (j < 3) {
            return 3;
        } else if (j < 6) {
            return 4;
        } else {
            return 5;
        }
    } else {
        if (j < 3) {
            return 6;
        } else if (j < 6) {
            return 7;
        } else {
            return 8;
        }
    }
}

function isNotValidSector(sector, number, sectors) {
    if (sectors[sector].has(number)) return true;
    sectors[sector].set(number);
    return false;
}

function isNotValidColumn(column, number, columns) {
    if (columns[column].has(number)) return true;
    columns[column].set(number);
    return false;
}