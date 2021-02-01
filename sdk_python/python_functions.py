"""
This file have all python function cradpy library.
Every function have parameters in string format.
So in function created specific object and run function with correct parameters.
"""
import sys
sys.path.append("../sdk_python/lib")
import cradpy

DELAY = 4
NUMBER_OF_OPTIONS = 7  # For variables in reg_program_list

DELIMITER = ","  # for data from csv file, symbol divides columns
SYMBOL_SPLIT_OUT = "|"  # for data from csv file, symbol divides value in column
SYMBOL_SPLIT_IN = ";"  # for data from csv file,

DELEGATE = cradpy.ConnectedRadioDelegateImpl()
sdk_api = cradpy.ConnectedRadioAPI(DELEGATE)


def start(parameters: str):
    """
    Will call Start API with parameters
    In csv file all parameters saved in following position:
    lat, lng, geo_code, device_id, mfg_id, url, hash,
    :param parameters: string with parameters
    """
    parameters_for_start = parameters.split(
        SYMBOL_SPLIT_OUT)
    mfg_info = cradpy.MFG_INFO_T()
    mfg_info.lat = float(parameters_for_start[0])
    mfg_info.lng = float(parameters_for_start[1])
    mfg_info.geo_code = parameters_for_start[2]
    mfg_info.device_id = parameters_for_start[3]
    mfg_info.mfg_id = parameters_for_start[4]
    mfg_info.url = parameters_for_start[5]
    mfg_info.hash = parameters_for_start[6]
    if sdk_api.Start(mfg_info) != 0:
        print("Error in start function")


def get_le_data(parameters: str):
    """
    Function shows Event Info Available
    :param parameters: string with parameters
    """
    if sdk_api.GetLocalEventData(parameters) != 0:
        print("Error in get_le_data function")


def reg_program_list(parameters: str):
    """
    Read parameters,and assign it.CSV file, have a lot of packs,
    which are separated CHARACTER_SPLIT_OUT, and in pack - separated CHARACTER_SPLIT_IN
    In csv file all parameters saved in following position:
    !WARNING! First you should write value for location then all another:
    verified, tuner.band, tuner.freq_khz, tuner.channel_sid,
    tuner.is_digital,
    fm.pi_code, fm.callsign,
    hd.ssn, hd.station_id ,hd.country_code ,hd.station_lat,
    hd.station_lon, hd.service_display_name
    :param parameters: string with parameters from csv
    """
    parameters_for_reg_program_list = parameters.split(SYMBOL_SPLIT_OUT)
    # we use -1 because first param is location
    number_of_lists = len(parameters_for_reg_program_list) - 1

    reg_program_list_info = cradpy.PROGRAM_REGISTRATION_LIST_INFO_T()
    reg_program_list_info.list = [cradpy.PROGRAM_REGISTRATION_INFO_T()
                                  for _ in range(number_of_lists)]

    location = parameters_for_reg_program_list[0].split(SYMBOL_SPLIT_IN)
    loc = cradpy.LOCATION_INFO_T()
    loc.latitude = float(location[0])
    loc.longitude = float(location[1])

    parameters_for_reg_program_list = parameters_for_reg_program_list[1:]
    i = 0  # counter
    while i < number_of_lists:
        value = parameters_for_reg_program_list[i]. \
            split(SYMBOL_SPLIT_IN)  # list of parameters
        reg_program_list_info.list[i].verified = bool(value[0])
        reg_program_list_info.list[i].tuner.band = int((value[1]))
        reg_program_list_info.list[i].tuner.freq_khz = int((value[2]))
        reg_program_list_info.list[i].tuner.channel_sid = int((value[3]))
        reg_program_list_info.list[i].tuner.is_digital = bool(value[4])
        reg_program_list_info.list[i].fm.pi_code = int((value[5]))
        reg_program_list_info.list[i].fm.callsign = value[6]

        if len(value) > NUMBER_OF_OPTIONS:
            reg_program_list_info.list[i].hd.ssn = value[7]
            reg_program_list_info.list[i].hd.station_id = int((value[8]))
            reg_program_list_info.list[i].hd.country_code = int((value[9]))
            reg_program_list_info.list[i].hd.station_lat = float(value[10])
            reg_program_list_info.list[i].hd.station_lon = float(value[11])
            reg_program_list_info.list[i].hd.service_display_name = value[12]
        i += 1

    if sdk_api.RegisterProgramList(
            reg_program_list_info, loc) != 0:
        print("Error in  reg_program_list")


def reg_location(parameters: str):
    """
    Save your correct location
    :param parameters: string with parameters
    """
    parameters_for_reg_location = parameters.split(
        SYMBOL_SPLIT_OUT)
    loc = cradpy.LOCATION_INFO_T()
    loc.latitude = float(parameters_for_reg_location[0])
    loc.longitude = float(parameters_for_reg_location[1])
    if sdk_api.RegisterLocationInfo(loc) != 0:
        print("Error in  reg_location")


def get_version(parameters: str):
    """
    Shows version API
    :param parameters: string with parameters
    """
    version = str()
    result, version = sdk_api.GetVersion(version)
    print(version, parameters)
    if result != 0:
        print("Error in version function")


def search_le(parameters: str):
    """

    Read parameters,and assign it to specific object called LE_SEARCH_DATA_T
    In csv all parameters in following order :
    lat,lng,type,artistName,genreId,range,lang,
    dayLimit,compact,limit, cursor, stripHTML, nonMusicResults
    :param parameters: string with parameters
    """
    search_query = parameters.split(SYMBOL_SPLIT_OUT)
    parameters_for_search_le = cradpy.LE_SEARCH_DATA_T()
    parameters_for_search_le.lat = float(search_query[0])
    parameters_for_search_le.lng = float(search_query[1])
    parameters_for_search_le.type = search_query[2]
    parameters_for_search_le.artistName = search_query[3]
    parameters_for_search_le.genreId = int(search_query[4])
    parameters_for_search_le.range = search_query[5]
    parameters_for_search_le.lang = search_query[6]
    parameters_for_search_le.dayLimit = int(search_query[7])
    parameters_for_search_le.compact = bool(search_query[8])
    parameters_for_search_le.limit = int(search_query[9])
    parameters_for_search_le.cursor = search_query[10]
    parameters_for_search_le.stripHTML = bool(search_query[11])
    parameters_for_search_le.nonMusicResults = bool(search_query[12])

    if sdk_api.SearchLocalEvents(parameters_for_search_le) != 0:
        print("Error in search_le function")


def stop():
    """
    Will call Stop API.
    :param parameters: string with parameters
    """
    if sdk_api.Stop() != 0:
        print("Error in stop ")


def output_json(parameters: str) -> str:
    """
    Take path to expected file
    :param parameters: string with parameters
    """
    return parameters
