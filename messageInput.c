// variables accessed by all functions
int numOfRows;
int numOfColumns;
char* table;

// actually creating the table
void createTable()
{
    int src, dst;

    // name and pid
    table[0] = (char*)malloc(numOfRows * sizeof(int));
    table[0][0] = 'name';
    table[1] = (char*)malloc(numOfRows * sizeof(int));
    table[1][0] = 'pid';

    // all the other columns
    for (int dst = 2; dst < numOfColumns; dst++)
        table[dst] = (int*)malloc(numOfRows * sizeof(int));

    // set pid
    int pid = -10;
    for (src = 1; src < numOfRows; src++)
    {
        dst = src + 1;
        table[dst][0] = (char)pid; // across the top
        table[1][src] = (char)pid; // down the side
        pid++;
    }
}

// make table bigger
void resizeTable()
{
    int newNumOfRows = numOfRows * 1.5, src, dst;
    char *biggerTable = (char*)malloc(newNumOfRows+1 * sizeof(char))
    createTable(biggerTable, newNumOfRows);
    // now I have old table (full) and new table 1.5x bigger (empty)

    // copy proc names from old table to new table
    for (src = 1; src < numOfRows; src++)
        biggerTable[0][src] = table[0][src];
    // copy proc counts
    for (dst = 2; dst < numOfColumns; dst++)
    {
        for (src = 1; src < numOfRows; src++)
            biggerTable[dst][src] = table[dst][src];
    }
    delete [] table;
    table = biggerTable;
    numOfRows = newNumOfRows;
    numOfColumns = numOfRows + 1;
}

// make the table the first time
void initTable()
{
    numOfRows = 18;
    numOfColumns = 19;
    table = (char*)malloc(numOfColumns * sizeof(char))

    createTable();

    // set everything to 0 except 'name' & 'pid' headers
    for (dst = 2; dst < numOfColumns; dst++)
    {
        for (src = 1; src < numOfRows; src++)
            table[dst][src] = 0;
    }
}

void messageTableInsert(register struct proc *caller_ptr, endpoint_t dst_e)
{
    int src, dst;
    bool inserted = false;

    // find where it needs to be inserted
  retry_insert:
    for (src = 1; src < numOfRows && !inserted; src++)
    {
        dst = src + 1;
        // if process not in table
        if (table[0][src] == 0)
        {
            // puts name of caller in name column
            table[0][src] = caller_ptr;
            // increments number from 0  to 1
            table[dst][src]++;
            inserted = true;
        } // if found in table
        else if (table[0][scrProc] == caller_ptr)
        {
            table[dst][src]++;
            inserted = true;
        }
    }
    // if table is full, make table bigger then insert
    if (!inserted)
    {
        resizeTable(table, numOfRows);
        goto retry_insert;
    }
}
