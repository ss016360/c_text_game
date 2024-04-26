  // Assume connections.csv has been loaded into an array of connections:
  int connections[][3] = {
    {0, 4, 7},
    {3, 2, 2},
    {2, 4, 5},
    {7, 8, 3},
    {0, 2, 9},
    {2, 5, 4},
    {7, 6, 6},
    {6, 3, 9},
    {3, 8, 8},
    {4, 7, 9}
  };

  // ... (rest of the code remains unchanged)

  // Modify the connection creation loop
  for (int i = 0; i < numLines; i++) {
    // Get the connections for the current room from connections.csv
    int numConnections = 3; // Assuming each room has 3 connections based on connections.csv
    for (int j = 0; j < numConnections; j++) {
      int roomToConnectTo = connections[i][j]; // Get the room index to connect to
      connection newConnection;

      // Set up the connection
      newConnection.room1 = &rooms[i];
      newConnection.room2 = &rooms[roomToConnectTo];

      // Add the connection to the room
      rooms[i].connections = realloc(rooms[i].connections, sizeof(connection) * (rooms[i].numConnections + 1));
      rooms[i].connections[rooms[i].numConnections] = newConnection;
      rooms[i].numConnections++;

      // Add the connection to the other room
      rooms[roomToConnectTo].connections = realloc(rooms[roomToConnectTo].connections, sizeof(connection) * (rooms[roomToConnectTo].numConnections + 1));
      rooms[roomToConnectTo].connections[rooms[roomToConnectTo].numConnections] = newConnection;
      rooms[roomToConnectTo].numConnections++;
    }
  }
