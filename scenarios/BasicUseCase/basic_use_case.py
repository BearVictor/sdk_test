"""
Scenario - Basic Use Case. This scenario run the following function:
start -> get_version -> reg_location -> reg_program_list -> stop
All callback are save in delegate_output.json
"""
import csv
import time
import sys
sys.path.append("..")
import cradpy



DELIMITER = ";"  # for csv file
SYMBOL_SPLIT_OUT = "|"  # for string, which read from csv file
SYMBOL_SPLIT_IN = ","  # for string, in list of data from csv file
NUMBER_OF_OPTIONS = 7  # For variables in reg_program_list
DELAY = 4


class BasicUseCase:
    """The class where run all scenario commands"""
    __delegate = cradpy.ConnectedRadioDelegateImpl()
    __sdk_api = cradpy.ConnectedRadioAPI(__delegate)
    __loc = cradpy.LOCATION_INFO_T()
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

    def version_function(self,):
        """
        This is the second function in scenario.
        Shows version of sdk
        """
        version = str()
        result, version = self.__sdk_api.GetVersion(version)
        print(version)
        if result != 0:
            print("Error in version function")

    def register_location_function(self):
        """
        This is the third function in scenario.
        Read parameters,and assign it.
        In csv file all parameters saved in following position:
        latitude, longitude
        """
        parameters_for_reg_location = self.all_parameters["reg_location"].split(
            SYMBOL_SPLIT_OUT)

        self.__loc.latitude = float(parameters_for_reg_location[0])
        self.__loc.longitude = float(parameters_for_reg_location[1])
        if self.__sdk_api.RegisterLocationInfo(self.__loc) != 0:
            print("Error in  reg_location")

    def reg_program_list_function(self):
        """
        This is the fourth function in scenario.
        Read parameters,and assign it.CSV file, have a lot of packs,
        which are separated CHARACTER_SPLIT_OUT, and in pack - separated CHARACTER_SPLIT_IN
        In csv file all parameters saved in following position:
        verified, tuner.band, tuner.freq_khz, tuner.channel_sid,
         tuner.is_digital,
        fm.pi_code, fm.callsign,
        hd.ssn, hd.station_id ,hd.country_code ,hd.station_lat,
        hd.station_lon, hd.service_display_name
        """
        parameters_for_reg_program_list = self.all_parameters["reg_program_list"].\
            split(SYMBOL_SPLIT_OUT)
        number_of_lists = len(parameters_for_reg_program_list)

        reg_program_list_info = cradpy.PROGRAM_REGISTRATION_LIST_INFO_T()
        reg_program_list_info.list = [cradpy.PROGRAM_REGISTRATION_INFO_T()
                                      for _ in range(number_of_lists)]

        i = 0  # counter
        while i < number_of_lists:
            value = parameters_for_reg_program_list[i].\
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

        if self.__sdk_api.RegisterProgramList(
                reg_program_list_info, self.__loc) != 0:
            print("Error in  reg_program_list")

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
        arameters_pack: number with parameters from the CSV file using
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
    In this function, we run the commands in following order:
        start -> get_le_data -> search_le -> stop
    :param parameters_pack: witch parameters from csv file should take
    :return: path to expected json,where exopected data
    """

    start_time = time.time()

    basic_use_case = BasicUseCase(parameters_pack)
    basic_use_case.read_csv_file()

    list_of_scene = [basic_use_case.start_function,
                     basic_use_case.version_function,
                     basic_use_case.register_location_function,
                     basic_use_case.reg_program_list_function,
                     basic_use_case.stop_function]

    for scene in list_of_scene:
        scene()
        time.sleep(DELAY)

    print("Finished successfully", time.time() - start_time)
    return basic_use_case.get_path_to_expected_json()


if __name__ == '__main__':
    scenario(0)
