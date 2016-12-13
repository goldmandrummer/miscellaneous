var random = { 
  directions: [ {
    routes: [{ legs: [{ steps: [{ travel_mode: 'WALKING' }] }] }]
  }, {
    routes: [{ legs: [{ steps: [{ travel_mode: 'BICYCLING' }] }] }]
  }, {
    routes: [{ legs: [{ steps: [{ travel_mode: 'WALKING' }] }] }]
  }, {
    routes: [{ legs: [{ steps: [{ travel_mode: 'BUS' }] }] }]
  } ], // google.maps.DirectionsResult
  rank: 0, // -1 invalid, 0 optimal, 1 forced, 2 super forced
  stationMarkers: [], // google.maps.Marker
  msg: '', // Including bikeshare is no more convenient. If ..., see bikeshare pins on map.
  totalDirs: 7, // directions.length==totalDirs => isComplete=true (-1 avoids issue on 0)
  isComplete: true // Flag to know when ready for DirectionsRenderer
};