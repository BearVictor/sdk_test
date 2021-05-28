"""This file has a function that passed parameters to sdk-lib function

This file have all python function cradpy library.
Every function have parameters in string format.
So in function created specific object and run function with correct parameters.
"""

import inspect
import os
import sys
sys.path.append("./sdk-python/lib")
sys.setrecursionlimit(1000)
import cradpy

DELAY = 5
NUMBER_OF_OPTIONS = 7  # For variables in reg_program_list

COMMANDS_DELIMITER = ","  # delimit columns in scenarios CSV
PARAMETERS_DELIMITER = "|"  # delimit parameters in commands columns
SYMBOL_SPLIT_IN = ";"  # group parameters in commands columns

# (for commands which may accept list of complex parameters)

DELEGATE = cradpy.ConnectedRadioDelegateImpl()
sdk_api = cradpy.ConnectedRadioAPI(DELEGATE)


def list_to_dict(data: list) -> dict:
    """
    Make dictionary object from the list of lists with structure [key , value]
    :param data: list of lists
    :return: dict
    """
    value_dict = {}
    if len(data) > 0:
        if "cradpy" in (str(data[0].__class__)):
            attributes = [a for a in dir(data[0]) if "__" not in a]
            for attr in attributes:
                value_dict[attr] = ""
            return value_dict
        if len(data) > 1:
            for value in data:
                value_dict[value[0]] = value[1]
        else:
            return data[0]


def make_pretty(list_of_lists: list) -> list:
    """
    Take parameter with a list of lists, which contain another list.
    This function process all of the lists and make a dictionary with keys and value
    :param list_of_lists: parameter from callbacks
    :return: list with dictionary
    """
    big_list = []
    #print('\nlist of list ', list_of_lists)
    for value in list_of_lists:
        #print('\nValue', value)
        value_dict = {}
        for item in value:
            print('\nItem', item)
            if not isinstance(item, list) or len(item)<1:
                big_list.append(value_dict)
            else:
                if len(item)<2:
                    item=item[0]

                if isinstance(item, list) and len(item) > 0:
                    small_dict = {}
                    print(item)
                    try:
                         for data in item:

                            print('\nData', data)
                            small_dict[data[0]] = data[1] if not isinstance(
                                data[1], list) else list_to_dict(data)
                         value_dict[item[0]] = small_dict
                         print('\nvalue dict', value_dict)
                         continue
                    except TypeError:
                        pass

                    #value_dict[item[0]] = item[1]
                big_list.append(value_dict)
    print('\n big', big_list)
    return big_list


def make_dict_from_callbacks(data_from_callbacks: dict) -> dict:
    """
    Process all data from callbacks with list objects to dictionary objects
    :param data_from_callbacks: dictionary with list of lists
    :return: dictionary without list objects
    """
    processed_dictionary = {}
    print('\ndata', data_from_callbacks)
    for key in data_from_callbacks.keys():
        value_dict = {}
        for value in data_from_callbacks[key]:
            #print('\nvalue', (value), ' value1', value[1])
            if isinstance(value[1], list):
                pretty_list_of_genres = make_pretty(value[1])
                value_dict[value[0]] = pretty_list_of_genres
                continue
            value_dict[value[0]] = value[1]
        processed_dictionary[key] = value_dict
    return processed_dictionary


def get_list_of_callback() -> list:
    """
    Get all callbacks.
    Rename callbacks from functions .
    Cut `On` and add `Data` for delegate object
    :return:
    """
    list_of_callbacks = DELEGATE.CallbacksList  # get all callbacks during scenario
    # print('all callbacks')
    delegate_name_callbacks = []  # empty list for callback name for delegate object
    for callback in list_of_callbacks:
        delegate_name_callbacks.append(callback[2:])
    print('\nALL CALLBACKS', list_of_callbacks, '\n')
    return delegate_name_callbacks


def get_attribute(name_class: str) -> list:
    """
    get all attibutes from class like list [name , value]
    :param name_class: name of class
    :return: list of lists attributes
    """
    attributes = inspect.getmembers(
        name_class, lambda a: not (
            inspect.isroutine(a)))
    all_attributes = [list(a) for a in attributes if not (
            a[0].startswith('__') or a[0].endswith('__') or "counter" in a[0])]
    return all_attributes


def get_data_from_list(dictionary_data: dict) -> dict:
    """
    Make verification,if some value cradpy classe.
    If yes we get data from them
    :param dictionary_data: dict for verification
    :return: update dict
    """
    data_from_list = {}

    for i in dictionary_data:
        dict2 = []
        for j in dictionary_data[i]:
            if i == 'ImagesAvailable':
                print(special_condition_for_image_available(dictionary_data[i]))
            else:
                dict2.append((main_dfs(j)))
                data_from_list[i] = dict2
    # h={'LiveDataAvailable': [['adData', []], ['broadcastId', '00011'], ['duration', 0], ['id', '1118'], ['musicData', [['album', '24K Magic'], ['artist', 'Bruno Mars'], ['conradAlbumId', ''], ['conradArtistId', ''], ['conradTrackId', ''], ['enableShare', False], ['enableThumbs', False], ['genreIds', []], ['images', [[['isDefault', True], ['type', 'album'], ['url', 'https://alt.dev.canradtest.com/livedata_info/97.9-HD1/6da95bb862f1f60338ed51fed4bdcadc.jpg'], ['urlHiRes', '']]]], ['title', '24K Magic']]], ['nmpData', [['conradArtistId', ''], ['conradTrackId', ''], ['enableShare', False], ['enableThumbs', False], ['images', [[['isDefault', False], ['type', ''], ['url', ''], ['urlHiRes', '']]]], ['program', 'The Priestly Show - Afternoons on MIX 106.5'], ['subject', ''], ['title', "It's the Priestly Program"]]], ['type', 'music']]}
    # for i in h["LiveDataAvailable"]:
    #     print(i)
    # data_from_callbacks = make_dict_from_callbacks(h)
    print('\nOutput\n', data_from_list)
    #return data_from_list


def special_condition_for_image_available(data):
    get_attr1 = get_attribute(data[1][1])
    get_attr2 = get_attribute(get_attr1[2][1])
    get_attr3 = get_attribute(get_attr2[1][1])
    # print(get_attr3) # ImageAvailable bug
    return data


def obj_dfs(data):
    current_list = []
    variable_list = get_attribute(data)
    for i in variable_list:
        current_list.append(main_dfs(i))
    return current_list


def list_dfs(data):
    current_list = []
    for i in data:
        current_list.append(main_dfs(i))
    return current_list


def dict_dfs(data):
    current_list = []
    for i in data.values():
        current_list.append(main_dfs(i))
    return current_list


def main_dfs(data):
    if isinstance(data, list) or isinstance(data, tuple):
        return list_dfs(data)
    elif isinstance(data, dict):
        return dict_dfs(data)
    elif isinstance(data, str) or isinstance(data, int) or isinstance(data, bool) or isinstance(data, float):
        return data
    else:
        return obj_dfs(data)


def special_condition_for_broadcastdata(all_attributes):
    """
    Callback return specific path to cradpy object,so we need take it
    :param all_attributes: attribute from LastBroadcastsAvailableData callback
    """
    # try:
    #     if len(all_attributes[0][1]) > 0:
    #         for i in range(len(all_attributes[0][1])):
    #             all_attributes[0][1][i][1][1] = get_attribute(
    #                 all_attributes[0][1][i][1][1])
    #             all_attributes[0][1][i][1][1][28][1] = get_attribute(
    #                 all_attributes[0][1][i][1][1][28][1])
    # except IndexError:
    #     pass


def combine_two_dict(first_dict: dict, second_dict: dict) -> dict:
    """
    compare keys in two dictionaries. If keys the same, combine their value to a list
    :param first_dict: the main dict in which we write new values with the same key
    :param second_dict: the support dict . if keys the same in the main dict we add value
    :return: first_dict
    """
    for key in first_dict.keys():
        if key in second_dict:
            first_dict[key] = [first_dict.get(key), second_dict.get(key)]
    return first_dict


def is_keys(var_dict: dict, key: str) -> bool:
    """
    make verification: is key in dict
    """
    return True if key in var_dict else False


def process_data_from_callback() -> dict:
    """
    Renames callback name for delegate object.
    Get attribute ( data which return callback) and
    save into dictionary object. Also make verification.
    If dict have unpacked cradpy classes.
    :return: dict with data from all callback
    """
    scenario_callback, data_with_same_key = {}, {}
    list_of_callback = get_list_of_callback()
    for callback in list_of_callback:
        data_from_callback = getattr(DELEGATE, callback)
        all_attributes = get_attribute(data_from_callback)
        if "cradpy" in str(type(all_attributes[0][1])):
            cradpy_class = all_attributes.pop()[1]
            all_attributes = (get_attribute(cradpy_class))
        if is_keys(scenario_callback, callback):
            data_with_same_key.update({callback: all_attributes})
        scenario_callback.update({callback: all_attributes})

    #scenario_callback, data_with_same_key = get_data_from_list(scenario_callback), get_data_from_list(data_with_same_key)
    scenario_callback = get_data_from_list(scenario_callback)
    #print('\nscenario callbaack', scenario_callback)
    #if 'ImagesAvailable' in list_of_callback:
    #special_condition_for_broadcastdata(scenario_callback["ImagesAvailable"])

    return scenario_callback


def register_device(parameters: str):
    """
    Will call RegisterDevice API with parameters
    In csv file all parameters are expected to be in the following order:
    url, mfg_id, mfg_secret, lat, lng, brand, mfg, device, model, serial, version
    :param parameters: string with parameters read from csv
    """
    csv_params = parameters.split(PARAMETERS_DELIMITER)
    dev_info = cradpy.DEVICE_REGISTER_INFO_T()
    dev_info.url = os.getenv(csv_params[0], "")
    dev_info.mfg_id = os.getenv(csv_params[1], "")
    dev_info.mfg_secret = os.getenv(csv_params[2], "")
    dev_info.lat = float(csv_params[3])
    dev_info.lng = float(csv_params[4])
    dev_info.brand = csv_params[5]
    dev_info.mfg = csv_params[6]
    dev_info.device = csv_params[7]
    dev_info.model = csv_params[8]
    dev_info.serial = csv_params[9]
    dev_info.version = csv_params[10]

    if sdk_api.RegisterDevice(dev_info) != 0:
        print("Error in register device function")


def start(parameters: str):
    """
    Will call Start API with parameters
    In csv file all parameters saved in following position:
    lat, lng, geo_code, device_id, mfg_id, url, hash,
    :param parameters: string with parameters
    """
    parameters_for_start = parameters.split(
        PARAMETERS_DELIMITER)
    mfg_info = cradpy.MFG_INFO_T()
    mfg_info.lat = float(parameters_for_start[0])
    mfg_info.lng = float(parameters_for_start[1])
    mfg_info.geo_code = parameters_for_start[2]
    mfg_info.device_id = os.getenv(parameters_for_start[3], "")
    mfg_info.mfg_id = os.getenv(parameters_for_start[4], "")
    mfg_info.url = os.getenv(parameters_for_start[5], "")
    mfg_info.hash = os.getenv(parameters_for_start[6], "")
    if sdk_api.Start(mfg_info) != 0:
        print("Error in start function")


def stop():
    """
    Will call Stop API.
    :param parameters: string with parameters
    """
    if sdk_api.Stop() != 0:
        print("Error in stop ")


def get_version(parameters: str):
    """
    Shows version API
    :param parameters: string with parameters
    """
    version = str()
    result, version = sdk_api.GetVersion(version)
    if result != 0:
        print("Error in version function")


def get_genres(parameters: str):
    """
    Function shows all genres
    :param parameters: string with parameters
    """
    if sdk_api.GetGenres(parameters) != 0:
        print("Error in get_genres function")


def get_broadcast(parameters: str):
    """
    Assign parameters to function
    In csv: id,lat,lon
    :param parameters: string with parameters
    """
    parameters_for_get_broadcast = parameters.split(PARAMETERS_DELIMITER)
    id_broadcast = parameters_for_get_broadcast[0]

    loc = cradpy.LOCATION_INFO_T()
    loc.latitude = float(parameters_for_get_broadcast[1])
    loc.longitude = float(parameters_for_get_broadcast[2])

    if sdk_api.GetBroadcastData(id_broadcast, loc) != 0:
        print("Error in get_broadcast function")


def get_broadcast_list(parameters: str):
    """
    Assign parameters to function
    In csv: lat,lon
    :param parameters: string with parameters
    """
    parameters_for_get_broadcast = parameters.split(PARAMETERS_DELIMITER)

    loc = cradpy.LOCATION_INFO_T()
    loc.latitude = float(parameters_for_get_broadcast[0])
    loc.longitude = float(parameters_for_get_broadcast[1])

    if sdk_api.GetBroadcastList(loc) != 0:
        print("Error in get_broadcast_list function")


def get_live_data(parameters: str):
    """
    Assign parameters to function
    In csv: id,lat,lon,guide,tuned,preset
    :param parameters: string with parameters
    """
    # dont return callback
    parameters_for_get_broadcast = parameters.split(PARAMETERS_DELIMITER)

    id_brodcast = parameters_for_get_broadcast[0]

    loc = cradpy.LOCATION_INFO_T()
    loc.latitude = float(parameters_for_get_broadcast[1])
    loc.longitude = float(parameters_for_get_broadcast[2])

    disp = cradpy.eLiveDataDisplayPurpose(parameters_for_get_broadcast[3])

    if sdk_api.GetLiveData(id_brodcast, loc, disp) != 0:
        print("Error in get_live_data function")


def reg_program(parameters: str):
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
    parameters_for_reg_program_list = parameters.split(PARAMETERS_DELIMITER)
    reg_program_list_info = cradpy.PROGRAM_REGISTRATION_LIST_INFO_T()
    reg_program_list_info.list = [cradpy.PROGRAM_REGISTRATION_INFO_T()]

    loc = cradpy.LOCATION_INFO_T()
    loc.latitude = float(parameters_for_reg_program_list[0])
    loc.longitude = float(parameters_for_reg_program_list[1])

    reg_program_list_info.list[0].verified = bool(
        parameters_for_reg_program_list[2])
    reg_program_list_info.list[0].tuner.band = int(
        (parameters_for_reg_program_list[3]))
    reg_program_list_info.list[0].tuner.freq_khz = int(
        (parameters_for_reg_program_list[4]))
    reg_program_list_info.list[0].tuner.channel_sid = int(
        (parameters_for_reg_program_list[5]))
    reg_program_list_info.list[0].tuner.is_digital = bool(
        parameters_for_reg_program_list[6])
    reg_program_list_info.list[0].fm.pi_code = int(
        (parameters_for_reg_program_list[7]))
    reg_program_list_info.list[0].fm.callsign = parameters_for_reg_program_list[8]

    if len(parameters_for_reg_program_list) > NUMBER_OF_OPTIONS + 2:
        reg_program_list_info.list[0].hd.ssn = parameters_for_reg_program_list[9]
        reg_program_list_info.list[0].hd.station_id = int(
            (parameters_for_reg_program_list[10]))
        reg_program_list_info.list[0].hd.country_code = int(
            (parameters_for_reg_program_list[11]))
        reg_program_list_info.list[0].hd.station_lat = float(
            parameters_for_reg_program_list[12])
        reg_program_list_info.list[0].hd.station_lon = float(
            parameters_for_reg_program_list[13])
        reg_program_list_info.list[0].hd.service_display_name = parameters_for_reg_program_list[14]

    if sdk_api.RegisterProgramList(
            reg_program_list_info, loc) != 0:
        print("Error in reg_program_list")


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
    parameters_for_reg_program_list = parameters.split(PARAMETERS_DELIMITER)
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
        PARAMETERS_DELIMITER)
    loc = cradpy.LOCATION_INFO_T()
    loc.latitude = float(parameters_for_reg_location[0])
    loc.longitude = float(parameters_for_reg_location[1])
    if sdk_api.RegisterLocationInfo(loc) != 0:
        print("Error in  reg_location")


def reg_stream(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """
    # N/A callback
    parameters_for_reg_stream = parameters.split(
        PARAMETERS_DELIMITER)
    stream_info = cradpy.STREAMING_SERVICE_INFO_T()
    stream_info.service_name = parameters_for_reg_stream[0]
    stream_info.station = parameters_for_reg_stream[1]
    stream_info.format = parameters_for_reg_stream[2]
    stream_info.bit_rate = int(parameters_for_reg_stream[3])
    stream_info.stream_url = parameters_for_reg_stream[4]
    stream_info.broadcast_id = parameters_for_reg_stream[5]
    stream_info.serv_follow = bool(parameters_for_reg_stream[6])
    stream_info.duration = int(parameters_for_reg_stream[7])
    stream_info.error_status_code = parameters_for_reg_stream[8]

    loc = cradpy.LOCATION_INFO_T()
    loc.latitude = float(parameters_for_reg_stream[9])
    loc.longitude = float(parameters_for_reg_stream[10])
    stream_info.location = loc

    if sdk_api.RegisterStreamInfo(stream_info) != 0:
        print("Error in  reg_stream")


def reg_volume(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """
    volume = cradpy.VOLUME_LEVEL_INFO_T()
    volume.level = int(parameters)
    if sdk_api.RegisterVolumeEvent(volume) != 0:
        print("Error in reg_volume function")


def reg_presets(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """
    parameters_for_reg_presets = parameters.split(PARAMETERS_DELIMITER)
    count_of_presets = len(parameters_for_reg_presets)
    presets = cradpy.PRESET_STATIONS_INFO_T()
    presets.stations_list = [cradpy.PRESET_INFO_T()
                             for _ in range(count_of_presets)]
    i = 0  # counter
    while i < count_of_presets:
        value = parameters_for_reg_presets[i]. \
            split(SYMBOL_SPLIT_IN)  # list of parameters
        presets.stations_list[i].frequency_khz = int(value[0])
        presets.stations_list[i].channel_sid = int(value[1])
        presets.stations_list[i].broadcast_id = (value[2])
        i += 1

    if sdk_api.RegisterPresets(presets) != 0:
        print("Error in reg_presets function")


def reg_signal(parameters: str):
    """
    Assign parameters to function
    In csv: lat, lng, cdno, rssi
    :param parameters: string with parameters
    """
    parameters_for_reg_signal = parameters.split(PARAMETERS_DELIMITER)
    signal_data = cradpy.SIGNAL_DATA_T()
    signal_data.lat = float(parameters_for_reg_signal[0])
    signal_data.lng = float(parameters_for_reg_signal[1])
    signal_data.cdno = int(parameters_for_reg_signal[2])
    signal_data.rssi = int(parameters_for_reg_signal[3])

    if sdk_api.RegisterSignalStrength(signal_data) != 0:
        print("Error in reg_signal function")


def get_categories(parameters: str):
    """
    Assign parameters to function
    In csv : ipcCatPath, sort , limit , cursor
    :param parameters: string with parameters
    """
    parameters_for_get_categories = parameters.split(PARAMETERS_DELIMITER)

    category_query = cradpy.IPC_CATEGORY_QUERY_T()
    category_query.ipcCatPath = parameters_for_get_categories[0]
    category_query.sort = parameters_for_get_categories[1]
    category_query.limit = int(parameters_for_get_categories[2])
    category_query.cursor = parameters_for_get_categories[3]

    if sdk_api.GetIpcCategories(category_query) != 0:
        print("Error in get_categories function")


def get_content(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """
    parameters_for_get_content = parameters.split(PARAMETERS_DELIMITER)

    content_info_query = cradpy.IPC_CONTENT_INFO_QUERY_T()
    content_info_query.ipcContentId = parameters_for_get_content[0]
    content_info_query.type = parameters_for_get_content[1]

    if sdk_api.GetIpcContent(content_info_query) != 0:
        print("Error in get_content function")


def get_similar(parameters: str):
    """
    Assign parameters to function
    In csv : ipcContentId,limit,cursor
    :param parameters: string with parameters
    """
    parameters_for_get_similar = parameters.split(PARAMETERS_DELIMITER)

    content_query = cradpy.IPC_CONTENT_QUERY_T()
    content_query.ipcContentId = parameters_for_get_similar[0]
    content_query.limit = int(parameters_for_get_similar[1])
    content_query.cursor = parameters_for_get_similar[2]

    if sdk_api.GetIpcSimilarContent(content_query) != 0:
        print("Error in get_similar function")


def search_content(parameters: str):
    """
    Assign parameters to function
    search,type,limit,cursor,location,priority language country
    :param parameters: string with parameters
    """
    parameters_for_search_content = parameters.split(PARAMETERS_DELIMITER)

    search_data = cradpy.IPC_SEARCH_DATA_T()
    search_data.search = parameters_for_search_content[0]
    search_data.type = parameters_for_search_content[1]
    search_data.limit = int(parameters_for_search_content[2])
    search_data.cursor = parameters_for_search_content[3]
    search_data.location = parameters_for_search_content[4]
    search_data.priority = parameters_for_search_content[5]
    search_data.language = parameters_for_search_content[6]
    search_data.country = parameters_for_search_content[7]

    if sdk_api.SearchIpcContent(search_data) != 0:
        print("Error in search_content function")


def get_play_info(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """
    playback_id = parameters
    if sdk_api.GetIpcContentPlayInfo(playback_id) != 0:
        print("Error in get_play_info function")


def get_podcast_episodes(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """
    parameters_for_get_podcast_episodes = parameters.split(PARAMETERS_DELIMITER)

    content_query = cradpy.IPC_CONTENT_QUERY_T()
    content_query.ipcContentId = parameters_for_get_podcast_episodes[0]
    content_query.limit = int(parameters_for_get_podcast_episodes[1])
    content_query.cursor = parameters_for_get_podcast_episodes[2]
    if sdk_api.GetIpcPodcastEpisodes(content_query) != 0:
        print("Error in get_podcast_episodes function")


def get_latest_episode(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """
    if sdk_api.GetIpcPodcastLatestEpisode(parameters) != 0:
        print("Error in get_latest_episode function")


def get_le_data(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """
    if sdk_api.GetLocalEventData(parameters) != 0:
        print("Error in get_le_data function")


def search_le(parameters: str):
    """

    Read parameters,and assign it to specific object called LE_SEARCH_DATA_T
    In csv all parameters in following order :
    lat,lng,type,artistName,genreId,range,lang,
    dayLimit,compact,limit, cursor, stripHTML, nonMusicResults
    :param parameters: string with parameters
    """
    search_query = parameters.split(PARAMETERS_DELIMITER)
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


def identify(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """
    parameters_for_identify = parameters.split(PARAMETERS_DELIMITER)

    query_data = cradpy.ACR_IDENTIFY_QUERY_DATA_T()
    query_data.fingerprintBytes = int(parameters_for_identify[0])
    query_data.source = parameters_for_identify[1]
    query_data.broadcastId = parameters_for_identify[2]
    query_data.sampleOrigin = parameters_for_identify[3]

    if sdk_api.IdentifyAcrFingerprint(query_data) != 0:
        print("Error in identify function")


def report_action(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """
    # type is one or all? Not finish
    parameters_for_report_action = parameters.split(PARAMETERS_DELIMITER)

    action_data = cradpy.ACTION_DATA_T()
    # type_action = cradpy.REPORT_ACTION_TYPE_E()

    action_data.type = (parameters_for_report_action[0])
    action_data.lat = float(parameters_for_report_action[1])
    action_data.lng = float(parameters_for_report_action[2])
    action_data.broadcastId = parameters_for_report_action[3]
    action_data.liveId = parameters_for_report_action[4]
    action_data.target = parameters_for_report_action[5]
    action_data.content = parameters_for_report_action[6]

    if sdk_api.ReportAction(action_data) != 0:
        print("Error in report_action function")


def get_images(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """

    parameters_for_get_images = parameters.split(PARAMETERS_DELIMITER)

    image_list = cradpy.IMAGES_DATA_REQ_LIST_T()
    count_of_presets = len(parameters_for_get_images)
    image_list.imageDataList = [
        cradpy.IMAGE_DATA_REQ_MODEL() for _ in range(count_of_presets)]
    i = 0  # counter
    while i < count_of_presets:
        value = parameters_for_get_images[i]. \
            split(SYMBOL_SPLIT_IN)  # list of parameters
        # should rework
        # switch
        # image_type = cradpy.eImageTypes()
        #
        # image_list.imageDataList[i].image_type = (value[0])

        image_id = cradpy.IMAGE_ID_T()
        image_id.type = value[1]
        image_id.id = value[2]

        image_list.imageDataList[i].image_id = image_id
        image_list.imageDataList[i].url = value[3]
        i += 1

    if sdk_api.GetImages(image_list) != 0:
        print("Error in get_images function")


def get_image_mode(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """
    # TypeError: __init__(): incompatible constructor arguments. The
    # following argument types are supported:
    mode_param = int(parameters, base=16)
    mode = cradpy.IMAGE_MODE_T(mode_param)
    if sdk_api.GetImageMode(mode) != 0:
        print("Error in get_image_mode function")


def set_image_mode(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """
    # TypeError: __init__(): incompatible constructor arguments. The
    # following argument types are supported:
    mode = cradpy.IMAGE_MODE_T(parameters)
    if sdk_api.SetImageMode(mode) != 0:
        print("Error in set_image_mode function")


def factory_reset(parameters: str):
    """
    Assign parameters to function
    :param parameters: string with parameters
    """
    if sdk_api.FactoryReset() != 0:
        print("Error in factory_reset function")


def output_json(parameters: str) -> str:
    """
    Take path to expected file
    :param parameters: string with parameters
    """
    return parameters


def clear():
    """
    Clear all callbacks
    """
    DELEGATE.ClearCallbacksList()


def restart_callback_counter():
    """all callback start with 0 again"""
    DELEGATE.RestartCallbackCounter()
