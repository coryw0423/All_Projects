function varargout = HomeScreenPOS(varargin)
% HOMESCREENPOS MATLAB code for HomeScreenPOS.fig
%      HOMESCREENPOS, by itself, creates a new HOMESCREENPOS or raises the existing
%      singleton*.
%
%      H = HOMESCREENPOS returns the handle to a new HOMESCREENPOS or the handle to
%      the existing singleton*.
%
%      HOMESCREENPOS('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in HOMESCREENPOS.M with the given input arguments.
%
%      HOMESCREENPOS('Property','Value',...) creates a new HOMESCREENPOS or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before HomeScreenPOS_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to HomeScreenPOS_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help HomeScreenPOS

% Last Modified by GUIDE v2.5 28-Apr-2018 10:42:35

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @HomeScreenPOS_OpeningFcn, ...
                   'gui_OutputFcn',  @HomeScreenPOS_OutputFcn, ...
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


% --- Executes just before HomeScreenPOS is made visible.
function HomeScreenPOS_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to HomeScreenPOS (see VARARGIN)

% Choose default command line output for HomeScreenPOS
handles.output = hObject;

% CurrentOrderTotal = []
set(handles.CarryOutRadioButton, 'value' , 0);
set(handles.DriveThruRadioButton, 'value', 0);
set(handles.DineInRadioButton, 'value' , 0);
% Update handles structure
guidata(hObject, handles);
% CurrentOrder = {};
% FileID = fopen('Price List.csv')
% Contents = textscan(FileID , 'Delimiter' , ',');
% fclose(FileID);
% UIWAIT makes HomeScreenPOS wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = HomeScreenPOS_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;






% --- Executes on button press in ComboPushButton.
function ComboPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to ComboPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
ComboPOSv2

% --- Executes on button press in CustomOrderPushButton.
function CustomOrderPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to CustomOrderPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CustomOrderPOS

% --- Executes on button press in ManagerFunctionsPushButton.
function ManagerFunctionsPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to ManagerFunctionsPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
EnterPassword

% --- Executes on button press in TenderPushButton.
function TenderPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to TenderPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
TenderPOS


% --- Executes on button press in CarryOutRadioButton.
function CarryOutRadioButton_Callback(hObject, eventdata, handles)
% hObject    handle to CarryOutRadioButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
tic
% Hint: get(hObject,'Value') returns toggle state of CarryOutRadioButton


% --- Executes on button press in DineInRadioButton.
function DineInRadioButton_Callback(hObject, eventdata, handles)
% hObject    handle to DineInRadioButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
tic
% Hint: get(hObject,'Value') returns toggle state of DineInRadioButton


% --- Executes on button press in DriveThruRadioButton.
function DriveThruRadioButton_Callback(hObject, eventdata, handles)
% hObject    handle to DriveThruRadioButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
tic
% Hint: get(hObject,'Value') returns toggle state of DriveThruRadioButton
