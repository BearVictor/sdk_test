"""Compare dict from scenario_run script and expected json """
from scenario_run import scenarios_run
import json
import time


def test_use_case_0_initial_sdk_start_up():
    """
    This use case tests sdk starts as expected for the very first time
    When SDK starts for the very first time it's expected that conrad-sdk.db doesn't exist yet
     and SDK do following requests to CONRAD:
    - Register Device Query
    - Config Query
    - Default Images Download
    - Genre Query
    - Broadcast Query

    Expected callbacks:
    OnRegisterDeviceAvailable,
    OnGenresAvailable,
    OnConfigDataAvailable,
    OnImagesAvailable,
    OnMessageCodeAvailable
    See more detailed expectations at scenarios/expected-data/use-case-0-device-registration.json

    Note: this scenario is expected to be run before all others scenarios to instantiate DB with default data
    """
    data_from_callbacks, expected_path = scenarios_run("scenarios/csv-scenarios/use-case-0-device-registration.csv")

    with open(expected_path, "r") as file:
        expected_data = json.load(file)

    keys = sorted(list(data_from_callbacks.keys()))
    expected_keys = sorted(list(expected_data.keys()))

    assert keys == expected_keys

    for i in range(len(expected_keys)):
        callback_key = expected_keys[i]
        if callback_key == 'ConfigDataAvailable' or callback_key == 'ImagesAvailable':
            continue
        assert expected_data.get(callback_key) == data_from_callbacks.get(keys[i])


def test_use_case_1_sdk_ip_vs_registered_data_matching():
    """
    This use case tests if SDK does IP and registered data matching right. Expected queries to CONRAD are following.
    - Config Query
    - Genre Query
    - Broadcast Query
    - Download Images for matched stations

    Expected callbacks:
    OnGenresAvailable,
    OnConfigDataAvailable,
    OnImagesAvailable,
    OnMessageCodeAvailable
    OnBroadcastsAvailable
    See more detailed expectations at scenarios/expected-data/use-case-1-start-stop.json
    """
    data_from_callbacks, expected_path = \
        scenarios_run("scenarios/csv-scenarios/use-case-1-ip-vs-registered-data-matching.csv")

    with open(expected_path, "r") as file:
        expected_data = json.load(file)

    keys = sorted(list(data_from_callbacks.keys()))
    expected_keys = sorted(list(expected_data.keys()))

    assert keys == expected_keys
    # assert expected_data.get('BroadcastsAvailable') == data_from_callbacks.get('BroadcastsAvailable')



def test_use_case_2_matched_ip_stations_have_live_data():
    """
    This use case tests if SDK receives LiveData after stations with live data are matched with registered OTA stations
    - Config Query
    - Genre Query
    - Broadcast Query
    - Download Images for matched stations
    - AMQP events received and Live Data Query sent

    Expected callbacks:
    OnGenresAvailable,
    OnConfigDataAvailable,
    OnImagesAvailable,
    OnMessageCodeAvailable
    OnBroadcastsAvailable
    OnLiveDataAvailable
    See more detailed expectations at scenarios/expected-data/use-case-2-matched-ip-stations-have-live-data.json
    """
    data_from_callbacks, expected_path = \
        scenarios_run("scenarios/csv-scenarios/use-case-2-matched-ip-stations-have-live-data.csv")

    with open(expected_path, "r") as file:
        expected_data = json.load(file)

    keys = sorted(list(data_from_callbacks.keys()))
    expected_keys = sorted(list(expected_data.keys()))

    assert keys == expected_keys
    # assert expected_data.get('BroadcastsAvailable') == data_from_callbacks.get('BroadcastsAvailable')



