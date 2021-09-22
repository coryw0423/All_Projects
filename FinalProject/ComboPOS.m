function varargout = ComboPOS(varargin)
%COMBOPOS MATLAB code file for ComboPOS.fig
%      COMBOPOS, by itself, creates a new COMBOPOS or raises the existing
%      singleton*.
%
%      H = COMBOPOS returns the handle to a new COMBOPOS or the handle to
%      the existing singleton*.
%
%      COMBOPOS('Property','Value',...) creates a new COMBOPOS using the
%      given property value pairs. Unrecognized properties are passed via
%      varargin to ComboPOS_OpeningFcn.  This calling syntax produces a
%      warning when there is an existing singleton*.
%
%      COMBOPOS('CALLBACK') and COMBOPOS('CALLBACK',hObject,...) call the
%      local function named CALLBACK in COMBOPOS.M with the given input
%      arguments.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ComboPOS

% Last Modified by GUIDE v2.5 28-Apr-2018 17:20:33

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ComboPOS_OpeningFcn, ...
                   'gui_OutputFcn',  @ComboPOS_OutputFcn, ...
                   'gui_LayoutFcn',  [], ...
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


% --- Executes just before ComboPOS is made visible.
function ComboPOS_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   unrecognized PropertyName/PropertyValue pairs from the
%            command line (see VARARGIN)

% Choose default command line output for ComboPOS
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes ComboPOS wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = ComboPOS_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in HomePushButton.
function HomePushButton_Callback(hObject, eventdata, handles)
% hObject    handle to HomePushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in TenderPushButton.
function TenderPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to TenderPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Combo1PushButton.
function Combo1PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo1PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Combo2PushButton.
function Combo2PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo2PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Combo3PushButton.
function Combo3PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo3PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Combo4PushButton.
function Combo4PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo4PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Combo5PushButton.
function Combo5PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo5PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Combo6PushButton.
function Combo6PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo6PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in AddToOrderPushButton.
function AddToOrderPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to AddToOrderPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function CurrentTotalEditBox_Callback(hObject, eventdata, handles)
% hObject    handle to CurrentTotalEditBox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of CurrentTotalEditBox as text
%        str2double(get(hObject,'String')) returns contents of CurrentTotalEditBox as a double


% --- Executes during object creation, after setting all properties.
function CurrentTotalEditBox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to CurrentTotalEditBox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
