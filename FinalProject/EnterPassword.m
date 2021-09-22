function varargout = EnterPassword(varargin)
% ENTERPASSWORD MATLAB code for EnterPassword.fig
%      ENTERPASSWORD, by itself, creates a new ENTERPASSWORD or raises the existing
%      singleton*.
%
%      H = ENTERPASSWORD returns the handle to a new ENTERPASSWORD or the handle to
%      the existing singleton*.
%
%      ENTERPASSWORD('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in ENTERPASSWORD.M with the given input arguments.
%
%      ENTERPASSWORD('Property','Value',...) creates a new ENTERPASSWORD or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before EnterPassword_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to EnterPassword_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help EnterPassword

% Last Modified by GUIDE v2.5 23-Apr-2018 19:52:16

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @EnterPassword_OpeningFcn, ...
                   'gui_OutputFcn',  @EnterPassword_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before EnterPassword is made visible.
function EnterPassword_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to EnterPassword (see VARARGIN)

% Choose default command line output for EnterPassword
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes EnterPassword wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = EnterPassword_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function PasswordEditBox_Callback(hObject, eventdata, handles)
% hObject    handle to PasswordEditBox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of PasswordEditBox as text
%        str2double(get(hObject,'String')) returns contents of PasswordEditBox as a double


% --- Executes during object creation, after setting all properties.
function PasswordEditBox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to PasswordEditBox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
pushbuttonall_Callback(hObject, eventdata, handles)


% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
pushbuttonall_Callback(hObject, eventdata, handles)


% --- Executes on button press in pushbutton7.
function pushbutton7_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
pushbuttonall_Callback(hObject, eventdata, handles)


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
pushbuttonall_Callback(hObject, eventdata, handles)


% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
pushbuttonall_Callback(hObject, eventdata, handles)


% --- Executes on button press in pushbutton8.
function pushbutton8_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
pushbuttonall_Callback(hObject, eventdata, handles)


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
pushbuttonall_Callback(hObject, eventdata, handles)


% --- Executes on button press in pushbutton6.
function pushbutton6_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
pushbuttonall_Callback(hObject, eventdata, handles)


% --- Executes on button press in pushbutton9.
function pushbutton9_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
pushbuttonall_Callback(hObject, eventdata, handles)


% --- Executes on button press in pushbuttonzero.
function pushbuttonzero_Callback(hObject, eventdata, handles)
% hObject    handle to pushbuttonzero (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
pushbuttonall_Callback(hObject, eventdata, handles)


% --- Executes on button press in EnterPushButton.

% hObject    handle to EnterPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in EnterPushButton.
function EnterPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to EnterPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Password = get(handles.PasswordEditBox , 'string' )

if strcmp( Password , '1234' ) == true % pass is 1234
     ManagerFunctions% accept the password
     close(EnterPassword)
else
    msgbox('Your password was not accepted.') % reject the entry
end


% --- Executes on button press in HomePushButton.
function HomePushButton_Callback(hObject, eventdata, handles)
% hObject    handle to HomePushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close(EnterPassword)

function pushbuttonall_Callback(hObject, eventdata, handles)
CurrentValue = get( handles.PasswordEditBox , 'string' );
CurrentValue = [ CurrentValue get(hObject, 'string' ) ];
set( handles.PasswordEditBox, 'string', CurrentValue );


% --- Executes on button press in DeletePushButton.
function DeletePushButton_Callback(hObject, eventdata, handles)
% hObject    handle to DeletePushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CurrentValue = get(handles.PasswordEditBox, 'string' );
if (length( CurrentValue ) > 0)
    CurrentValue = CurrentValue( 1 : 1 : length(CurrentValue) - 1 );
else
    % do nothing
end
set(handles.PasswordEditBox, 'string' , CurrentValue );

% --- Executes on button press in ClearAllPushButton.
function ClearAllPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to ClearAllPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.PasswordEditBox, 'string' , '');
