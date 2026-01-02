import json
from math import sqrt
from APIs.weatherAPI import get_weather_data
from APIs.roadAPI import get_road_data
import pandas as pd

# Distance calculator using coordinates for a school project

def calculateClosestStations(road_number: int):
    # Call road API
    road_df = get_road_data()

    # Filter for specific road (no forecast filter)
    target_road_df = road_df[road_df["road_number"] == road_number]

    if target_road_df.empty:
        return []

    road_records = target_road_df.to_dict(orient="records")

    # Call weather API
    weather_df = get_weather_data()
    weather_stations = weather_df.to_dict(orient="records")

    # List for data
    matched_data = []

    for road_point in road_records:
        coords_json_str = road_point.get("coords_json")

        if not coords_json_str:
            continue

        try:
            coords = json.loads(coords_json_str)
        except json.JSONDecodeError:
            continue

        if not coords or not isinstance(coords, list):
            continue

        candidate = coords[0]
        if isinstance(candidate, list) and isinstance(candidate[0], list):
            start_point = candidate[0]
        else:
            start_point = candidate

        if not isinstance(start_point, list) or len(start_point) < 2:
            continue

        # Sets coordinates for lon and lat
        road_lon, road_lat = start_point[0], start_point[1]

        # Starts the distance from infinity to guarantee the number will be smaller
        min_distance = float("inf")
        # Assigns the station to none when not checked any
        closest_station = None

        for station in weather_stations:
            # Assigns the coordinates for stations like for the road points to clarify
            slat = station.get("lat")
            slon = station.get("lon")
            # Checks if lat and lon has values
            if slat is None or slon is None:
                continue
              
            # Euclidean distance using lat/lon 
            dist = sqrt((road_lat - slat)**2 + (road_lon - slon)**2)
            # Determines the closest station
            if dist < min_distance:
                min_distance = dist
                closest_station = station
        
        # Check for duplicates
        if closest_station:
            station_id = closest_station.get("station_id")
            if station_id in used_stations:
                continue
            used_stations.add(station_id)

        if closest_station:
            matched_data.append({
                "section_id": road_point.get("section_id"),
                "station_id": closest_station.get("station_id"),
                "closest_station_name": closest_station.get("station_name"),
                "real_time_air_temp": closest_station.get("temperature"),
                "overall_road_condition": road_point.get("overall_road_condition")
            })

    # Creates a list with no duplicates
    unique = {}
    for item in matched_data:
        sid = item["station_id"]
        if sid not in unique:
            unique[sid] = {
                "closest_station_name": item["closest_station_name"],
                "real_time_air_temp": item["real_time_air_temp"],
                "overall_road_condition": item["overall_road_condition"]
            }

    return list(unique.values())
