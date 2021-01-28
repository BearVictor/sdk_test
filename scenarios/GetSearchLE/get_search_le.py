"""
Scenario - Get search LE. This scenario run the following function:
start -> get_le_data -> search_le -> stop
All callback are save in delegate_output.json
"""
import csv
import time
import sys
sys.path.append("..")
import cradpy


DELIMITER = ";"  # for csv file
SYMBOL_SPLIT_OUT = "|"  # for string, which read from csv file
DELAY = 4


class GetSearchLe:
    """The class where run all scenario commands"""
    __delegate = cradpy.ConnectedRadioDelegateImpl()
    __sdk_api = cradpy.ConnectedRadioAPI(__delegate)
    all_parameters = dict()

    def __init__(self, parameters_pack):
        self.parameters_pack = parameters_pack

    def start_function(self,):
        """
        This is the first function in scenario.
        Read parameters,and assign it.
        In csv file all parameters saved in following position:
        lat, lng, geo_code, device_id, mfg_id, url, hash,
        :return: None
        """
        parameters_for_start = self.all_parameters["start"].split(
            SYMBOL_SPLIT_OUT)
        mfg_info = cradpy.MFG_INFO_T()
        mfg_info.lat = float(parameters_for_start[0])
        mfg_info.lng = float(parameters_for_start[1])
        mfg_info.geo_code = parameters_for_start[2]
        mfg_info.device_id = parameters_for_start[3]
        mfg_info.mfg_id = parameters_for_start[4]
        mfg_info.url = parameters_for_start[5]
        mfg_info.hash = parameters_for_start[6]
        if self.__sdk_api.Start(mfg_info) != 0:
            print("Error in start function")

    def get_le_data_function(self):
        """
        This is the third function in scenario.
        Read parameters,and assign it.Run function
        """
        local_event_id = self.all_parameters["get_le_data"]
        if self.__sdk_api.GetLocalEventData(local_event_id) != 0:
            print("Error in get_le_data function")

    def search_le_function(self):
        """
        This is the fourth function in scenario.
        Read parameters,and assign it to specific object called LE_SEARCH_DATA_T
        In csv all parameters in following order :
        lat,lng,type,artistName,genreId,range,lang,
        dayLimit,compact,limit, cursor, stripHTML, nonMusicResults
        """
        search_query = self.all_parameters["search_le"].split(SYMBOL_SPLIT_OUT)
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

        if self.__sdk_api.SearchLocalEvents(parameters_for_search_le) != 0:
            print("Error in search_le function")

    def stop_function(self):
        """
        Last function which stopped all process
        """
        if self.__sdk_api.Stop() != 0:
            print("Error in stop ")

    def get_path_to_expected_json(self) -> str:
        "return path to json where save corret, exsepted data"
        return self.all_parameters["output_json"]

    def read_csv_file(self,):
        """
        Open csv file, which locate in currently directory.
        All rows are saved like dict object.
        All rows saved in common list
        parameters_pack: number with parameters from the CSV file using
        :return: dict with parameters
        """
        all_parameters_for_scenario = []
        with open('file.csv', newline='') as csvfile:
            reader = csv.DictReader(csvfile, delimiter=DELIMITER)
            for row in reader:
                all_parameters_for_scenario.append(row)

        # saved dict object
        self.all_parameters = all_parameters_for_scenario[self.parameters_pack]


def scenario(parameters_pack: int = 0) -> str:
    """
    In this function, we run commands in following list:
        start -> get_le_data -> search_le -> stop
    :param parameters_pack: witch parameters from csv file should take
    :return: path to expected json,where exopected data
    """

    start_time = time.time()

    get_search_le = GetSearchLe(parameters_pack)
    get_search_le.read_csv_file()

    list_of_scene = [get_search_le.start_function,
                     get_search_le.get_le_data_function,
                     get_search_le.search_le_function,
                     get_search_le.stop_function]

    for scene in list_of_scene:
        scene()
        time.sleep(DELAY)

    print("Finished successfully", time.time() - start_time)
    return get_search_le.get_path_to_expected_json()


if __name__ == '__main__':
    scenario()
