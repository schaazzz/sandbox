TestAppModule = null;
statusText = '---';

function moduleDidLoad() {
    TestAppModule = document.getElementById('test-app');
    updateStatus('SUCCESS');
}

function handleMessage(msgEvent) {
    $('#txt-output').val(msgEvent.data);
}

function pageDidLoad() {
    if (TestAppModule == null) {
        updateStatus('LOADING...');
    } else {
        updateStatus();
    }
}

function updateStatus(optMsg) {
    if (optMsg) {
        statusText = optMsg;
    }

    var statusField = document.getElementById('status-field');
    if (statusField) {
        statusField.innerHTML = statusText;
    }
}

$(document).ready(function() {
    var listener = document.getElementById('listener');

    listener.addEventListener('load', moduleDidLoad, true);
    listener.addEventListener('message', handleMessage, true);
    moduleDidLoad();

    $('#txt-input').keyup(function() {
        TestAppModule.postMessage($(this).val());
    });
});
