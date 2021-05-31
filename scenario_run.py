"""Automatically wrapper. Open .csv file, get scenario from them,and run following function."""
import csv
import time
import crad


def read_csv_file(path: str, parameters_pack: int) -> dict:
    """
    Open csv file located in the dir specified by path.
    All rows are saved like dict object.
    All rows saved in common list
    :param path:  path to .csv file
    :param parameters_pack: number with parameters from the CSV file using
    :return: dict with parameters
    """
    all_parameters_for_scenario = []
    with open(path, newline='') as csv_file:
        reader = csv.DictReader(csv_file, delimiter=crad.COMMANDS_DELIMITER)
        for row in reader:
            all_parameters_for_scenario.append(row)

    return all_parameters_for_scenario[parameters_pack]


def scenarios_run(path: str, parameters_pack: int = 0) -> (dict, str):
    """
    This method read csv file, extract data about order of API calls for specified scenario, then parse parameters
    and run scenario for different sets of parameters
    :param path:  path to .csv file with scenario and parameters
    :param parameters_pack: number of parameters from the CSV file using
    :return actual callbacks list, and  path to the json with expected callbacks for that set of data
    """
    all_parameters_for_scenario = read_csv_file(path, parameters_pack)  # save csv file
    name_of_functions = all_parameters_for_scenario.keys()  # save all name of function

    for name in name_of_functions:
        try:
            method_to_call = getattr(crad, name)
            if name == "output_json":
                expected_path = method_to_call(all_parameters_for_scenario[name])
            method_to_call(all_parameters_for_scenario[name])
        except AttributeError:
            print("module 'crad' has no attribute " + name)
            continue

    time.sleep(crad.DELAY)
    crad.stop()

    data_from_callbacks = crad.process_data_from_callback()

    return data_from_callbacks, expected_path

