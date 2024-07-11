object DM: TDM
  Height = 601
  Width = 866
  PixelsPerInch = 120
  object BAZA: TFDConnection
    Params.Strings = (
      'Database=MAGAZIN'
      'Server=CEALIC-PC'
      'OSAuthent=Yes'
      'DriverID=MSSQL')
    Connected = True
    LoginPrompt = False
    Left = 64
    Top = 32
  end
  object QAUTENTIFICARE: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      
        '               SELECT *,F.NUME AS FIRMA, O.NUME+'#39' '#39'+O.PRENUME AS' +
        ' OPERATOR,FO.TIP_ACCES AS ACCES'
      
        'FROM FIRMA F INNER JOIN FIRMA_OPERATOR FO ON F.FIRMA_ID=FO.FIRMA' +
        '_ID'
      
        '             INNER JOIN OPERATOR O ON O.OPERATOR_ID=FO.OPERATOR_' +
        'ID'
      'WHERE USERNAME=:USERNAME AND PASS=:PASS AND F.NUME=:NUME')
    Left = 64
    Top = 112
    ParamData = <
      item
        Name = 'USERNAME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'PASS'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'NUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end>
    object QAUTENTIFICAREFIRMA_ID: TFDAutoIncField
      FieldName = 'FIRMA_ID'
      Origin = 'FIRMA_ID'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = True
    end
    object QAUTENTIFICARENUME: TStringField
      FieldName = 'NUME'
      Origin = 'NUME'
      Size = 50
    end
    object QAUTENTIFICARECOD_FISCAL: TStringField
      FieldName = 'COD_FISCAL'
      Origin = 'COD_FISCAL'
      Size = 13
    end
    object QAUTENTIFICAREADRESA: TStringField
      FieldName = 'ADRESA'
      Origin = 'ADRESA'
      Size = 100
    end
    object QAUTENTIFICAREFIRMA_OPERATOR_ID: TFDAutoIncField
      FieldName = 'FIRMA_OPERATOR_ID'
      Origin = 'FIRMA_OPERATOR_ID'
      ReadOnly = True
    end
    object QAUTENTIFICAREFIRMA_ID_1: TIntegerField
      FieldName = 'FIRMA_ID_1'
      Origin = 'FIRMA_ID'
    end
    object QAUTENTIFICARETIP_ACCES: TStringField
      FieldName = 'TIP_ACCES'
      Origin = 'TIP_ACCES'
      Size = 10
    end
    object QAUTENTIFICAREOPERATOR_ID: TIntegerField
      FieldName = 'OPERATOR_ID'
      Origin = 'OPERATOR_ID'
    end
    object QAUTENTIFICAREOPERATOR_ID_1: TFDAutoIncField
      FieldName = 'OPERATOR_ID_1'
      Origin = 'OPERATOR_ID'
      ReadOnly = True
    end
    object QAUTENTIFICARENUME_1: TStringField
      FieldName = 'NUME_1'
      Origin = 'NUME'
      Size = 30
    end
    object QAUTENTIFICAREPRENUME: TStringField
      FieldName = 'PRENUME'
      Origin = 'PRENUME'
      Size = 30
    end
    object QAUTENTIFICAREFUNCTIA: TStringField
      FieldName = 'FUNCTIA'
      Origin = 'FUNCTIA'
    end
    object QAUTENTIFICAREUSERNAME: TStringField
      FieldName = 'USERNAME'
      Origin = 'USERNAME'
      Size = 10
    end
    object QAUTENTIFICAREPASS: TStringField
      FieldName = 'PASS'
      Origin = 'PASS'
      Size = 10
    end
    object QAUTENTIFICARECOD: TStringField
      FieldName = 'COD'
      Origin = 'COD'
      Size = 13
    end
    object QAUTENTIFICARETIP_ACCES_1: TIntegerField
      FieldName = 'TIP_ACCES_1'
      Origin = 'TIP_ACCES'
    end
    object QAUTENTIFICAREFIRMA: TStringField
      FieldName = 'FIRMA'
      Origin = 'FIRMA'
      Size = 50
    end
    object QAUTENTIFICAREOPERATOR: TStringField
      FieldName = 'OPERATOR'
      Origin = 'OPERATOR'
      ReadOnly = True
      Size = 61
    end
    object QAUTENTIFICAREACCES: TStringField
      FieldName = 'ACCES'
      Origin = 'ACCES'
      Size = 10
    end
  end
  object QLIBER: TFDQuery
    Connection = BAZA
    Left = 72
    Top = 184
  end
  object QUM: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      'SELECT * FROM UNIT_MASURA')
    Left = 304
    Top = 32
    object QUMUNIT_MASURA_ID: TFDAutoIncField
      FieldName = 'UNIT_MASURA_ID'
      Origin = 'UNIT_MASURA_ID'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = True
    end
    object QUMABREVIERE: TStringField
      FieldName = 'ABREVIERE'
      Origin = 'ABREVIERE'
      Size = 5
    end
    object QUMNUME: TStringField
      FieldName = 'NUME'
      Origin = 'NUME'
      Size = 10
    end
  end
  object DSQUM: TDataSource
    DataSet = QUM
    Left = 392
    Top = 32
  end
  object QPRODUS: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      'SELECT * FROM PRODUSE')
    Left = 304
    Top = 104
    object QPRODUSPRODUSE_ID: TFDAutoIncField
      FieldName = 'PRODUSE_ID'
      Origin = 'PRODUSE_ID'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = True
    end
    object QPRODUSDENUMIRE: TStringField
      FieldName = 'DENUMIRE'
      Origin = 'DENUMIRE'
      Size = 30
    end
    object QPRODUSCOD_PRODUS: TStringField
      FieldName = 'COD_PRODUS'
      Origin = 'COD_PRODUS'
    end
  end
  object DSQPRODUS: TDataSource
    DataSet = QPRODUS
    Left = 400
    Top = 104
  end
  object QEMITENT: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      'SELECT *FROM EMITENT')
    Left = 312
    Top = 184
    object QEMITENTEMITENT_ID: TFDAutoIncField
      FieldName = 'EMITENT_ID'
      Origin = 'EMITENT_ID'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = True
    end
    object QEMITENTDENUMIRE: TStringField
      FieldName = 'DENUMIRE'
      Origin = 'DENUMIRE'
      Size = 50
    end
    object QEMITENTIDNP: TStringField
      FieldName = 'IDNP'
      Origin = 'IDNP'
      Size = 15
    end
    object QEMITENTADRESA: TStringField
      FieldName = 'ADRESA'
      Origin = 'ADRESA'
      Size = 50
    end
  end
  object DSQEMITENT: TDataSource
    DataSet = QEMITENT
    Left = 408
    Top = 184
  end
  object QFACTURA: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      
        'SELECT O.NUME+'#39' '#39'+O.PRENUME AS OPERATOR,E.DENUMIRE AS EMITENT,PR' +
        'ET_VANZ-PRET_INTRARE AS DIF,'
      'PRET_INTRARE*TVA/100.0 AS PROCENT_TVA,*'
      'FROM'
      'RECEPTIE R INNER JOIN PRODUSE P ON R.PRODUSE_ID=P.PRODUSE_ID'
      
        '           INNER JOIN UNIT_MASURA UM ON UM.UNIT_MASURA_ID=R.UNIT' +
        '_MASURA_ID'
      
        #9#9'   INNER JOIN FACTURA_REC F ON F.FACTURA_REC_ID=R.FACTURA_REC_' +
        'ID'
      
        #9#9'   INNER JOIN FIRMA_OPERATOR FO ON FO.FIRMA_OPERATOR_ID=R.FIRM' +
        'A_OPERATOR_ID'
      #9#9'   INNER JOIN OPERATOR O ON O.OPERATOR_ID=FO.FIRMA_OPERATOR_ID'
      #9#9'   INNER JOIN EMITENT E ON E.EMITENT_ID=F.EMITENT_ID'
      'WHERE R.ACTIV=1 AND F.FACTURA_REC_ID=:ID')
    Left = 312
    Top = 264
    ParamData = <
      item
        Name = 'ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
    object QFACTURAOPERATOR: TStringField
      FieldName = 'OPERATOR'
      Origin = 'OPERATOR'
      ReadOnly = True
      Size = 61
    end
    object QFACTURAEMITENT: TStringField
      FieldName = 'EMITENT'
      Origin = 'EMITENT'
      Size = 50
    end
    object QFACTURADIF: TBCDField
      FieldName = 'DIF'
      Origin = 'DIF'
      ReadOnly = True
      Precision = 8
      Size = 2
    end
    object QFACTURAPROCENT_TVA: TFMTBCDField
      FieldName = 'PROCENT_TVA'
      Origin = 'PROCENT_TVA'
      ReadOnly = True
      Precision = 24
      Size = 7
    end
    object QFACTURARECEPTIE_ID: TFDAutoIncField
      FieldName = 'RECEPTIE_ID'
      Origin = 'RECEPTIE_ID'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = True
    end
    object QFACTURAPRODUSE_ID: TIntegerField
      FieldName = 'PRODUSE_ID'
      Origin = 'PRODUSE_ID'
    end
    object QFACTURAUNIT_MASURA_ID: TIntegerField
      FieldName = 'UNIT_MASURA_ID'
      Origin = 'UNIT_MASURA_ID'
    end
    object QFACTURAFACTURA_REC_ID: TIntegerField
      FieldName = 'FACTURA_REC_ID'
      Origin = 'FACTURA_REC_ID'
    end
    object QFACTURAFIRMA_OPERATOR_ID: TIntegerField
      FieldName = 'FIRMA_OPERATOR_ID'
      Origin = 'FIRMA_OPERATOR_ID'
    end
    object QFACTURASTOCK1: TIntegerField
      FieldName = 'STOCK1'
      Origin = 'STOCK1'
    end
    object QFACTURASTOCK2: TIntegerField
      FieldName = 'STOCK2'
      Origin = 'STOCK2'
    end
    object QFACTURAPRET_INTRARE: TBCDField
      FieldName = 'PRET_INTRARE'
      Origin = 'PRET_INTRARE'
      Precision = 7
      Size = 2
    end
    object QFACTURAPRET_VANZ: TBCDField
      FieldName = 'PRET_VANZ'
      Origin = 'PRET_VANZ'
      Precision = 7
      Size = 2
    end
    object QFACTURATVA: TIntegerField
      FieldName = 'TVA'
      Origin = 'TVA'
    end
    object QFACTURAACTIV: TBooleanField
      FieldName = 'ACTIV'
      Origin = 'ACTIV'
    end
    object QFACTURAPRODUSE_ID_1: TFDAutoIncField
      FieldName = 'PRODUSE_ID_1'
      Origin = 'PRODUSE_ID'
      ReadOnly = True
    end
    object QFACTURADENUMIRE: TStringField
      FieldName = 'DENUMIRE'
      Origin = 'DENUMIRE'
      Size = 30
    end
    object QFACTURACOD_PRODUS: TStringField
      FieldName = 'COD_PRODUS'
      Origin = 'COD_PRODUS'
    end
    object QFACTURAUNIT_MASURA_ID_1: TFDAutoIncField
      FieldName = 'UNIT_MASURA_ID_1'
      Origin = 'UNIT_MASURA_ID'
      ReadOnly = True
    end
    object QFACTURAABREVIERE: TStringField
      FieldName = 'ABREVIERE'
      Origin = 'ABREVIERE'
      Size = 5
    end
    object QFACTURANUME: TStringField
      FieldName = 'NUME'
      Origin = 'NUME'
      Size = 10
    end
    object QFACTURAFACTURA_REC_ID_1: TFDAutoIncField
      FieldName = 'FACTURA_REC_ID_1'
      Origin = 'FACTURA_REC_ID'
      ReadOnly = True
    end
    object QFACTURANR_FACTURA: TStringField
      FieldName = 'NR_FACTURA'
      Origin = 'NR_FACTURA'
    end
    object QFACTURADATA_FACTURA: TDateField
      FieldName = 'DATA_FACTURA'
      Origin = 'DATA_FACTURA'
    end
    object QFACTURAEMITENT_ID: TIntegerField
      FieldName = 'EMITENT_ID'
      Origin = 'EMITENT_ID'
    end
    object QFACTURAEMITENT_1: TStringField
      FieldName = 'EMITENT_1'
      Origin = 'EMITENT'
      Size = 100
    end
    object QFACTURAFIRMA_OPERATOR_ID_1: TFDAutoIncField
      FieldName = 'FIRMA_OPERATOR_ID_1'
      Origin = 'FIRMA_OPERATOR_ID'
      ReadOnly = True
    end
    object QFACTURAFIRMA_ID: TIntegerField
      FieldName = 'FIRMA_ID'
      Origin = 'FIRMA_ID'
    end
    object QFACTURATIP_ACCES: TStringField
      FieldName = 'TIP_ACCES'
      Origin = 'TIP_ACCES'
      Size = 10
    end
    object QFACTURAOPERATOR_ID: TIntegerField
      FieldName = 'OPERATOR_ID'
      Origin = 'OPERATOR_ID'
    end
    object QFACTURAOPERATOR_ID_1: TFDAutoIncField
      FieldName = 'OPERATOR_ID_1'
      Origin = 'OPERATOR_ID'
      ReadOnly = True
    end
    object QFACTURANUME_1: TStringField
      FieldName = 'NUME_1'
      Origin = 'NUME'
      Size = 30
    end
    object QFACTURAPRENUME: TStringField
      FieldName = 'PRENUME'
      Origin = 'PRENUME'
      Size = 30
    end
    object QFACTURAFUNCTIA: TStringField
      FieldName = 'FUNCTIA'
      Origin = 'FUNCTIA'
    end
    object QFACTURAUSERNAME: TStringField
      FieldName = 'USERNAME'
      Origin = 'USERNAME'
      Size = 10
    end
    object QFACTURAPASS: TStringField
      FieldName = 'PASS'
      Origin = 'PASS'
      Size = 10
    end
    object QFACTURACOD: TStringField
      FieldName = 'COD'
      Origin = 'COD'
      Size = 13
    end
    object QFACTURATIP_ACCES_1: TIntegerField
      FieldName = 'TIP_ACCES_1'
      Origin = 'TIP_ACCES'
    end
    object QFACTURAEMITENT_ID_1: TFDAutoIncField
      FieldName = 'EMITENT_ID_1'
      Origin = 'EMITENT_ID'
      ReadOnly = True
    end
    object QFACTURADENUMIRE_1: TStringField
      FieldName = 'DENUMIRE_1'
      Origin = 'DENUMIRE'
      Size = 50
    end
    object QFACTURAIDNP: TStringField
      FieldName = 'IDNP'
      Origin = 'IDNP'
      Size = 15
    end
    object QFACTURAADRESA: TStringField
      FieldName = 'ADRESA'
      Origin = 'ADRESA'
      Size = 50
    end
  end
  object DSQFACTURA: TDataSource
    DataSet = QFACTURA
    Left = 408
    Top = 264
  end
  object QDATEFACTURA: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      
        'SELECT E.EMITENT_ID,F.EMITENT,F.NR_FACTURA,F.DATA_FACTURA,COUNT(' +
        '*) AS NR_POZ,SUM(R.PRET_INTRARE) AS PRET_INTRARE,'
      
        'SUM(R.PRET_INTRARE*TVA/100.0) AS PRET_TVA,SUM(R.PRET_INTRARE)+SU' +
        'M(R.PRET_INTRARE*TVA/100.0) AS PRET_TOT'
      'FROM'
      'RECEPTIE R INNER JOIN PRODUSE P ON R.PRODUSE_ID=P.PRODUSE_ID'
      
        '           INNER JOIN UNIT_MASURA UM ON UM.UNIT_MASURA_ID=R.UNIT' +
        '_MASURA_ID'
      
        #9#9'   INNER JOIN FACTURA_REC F ON F.FACTURA_REC_ID=R.FACTURA_REC_' +
        'ID'
      
        #9#9'   INNER JOIN FIRMA_OPERATOR FO ON FO.FIRMA_OPERATOR_ID=R.FIRM' +
        'A_OPERATOR_ID'
      #9#9'   INNER JOIN OPERATOR O ON O.OPERATOR_ID=FO.FIRMA_OPERATOR_ID'
      #9#9'   INNER JOIN EMITENT E ON E.EMITENT_ID=F.EMITENT_ID'
      'WHERE R.ACTIV=1'
      'GROUP BY E.EMITENT_ID,F.EMITENT,F.NR_FACTURA,F.DATA_FACTURA')
    Left = 312
    Top = 344
    object QDATEFACTURAEMITENT: TStringField
      FieldName = 'EMITENT'
      Origin = 'EMITENT'
      Size = 100
    end
    object QDATEFACTURANR_FACTURA: TStringField
      FieldName = 'NR_FACTURA'
      Origin = 'NR_FACTURA'
    end
    object QDATEFACTURADATA_FACTURA: TDateField
      FieldName = 'DATA_FACTURA'
      Origin = 'DATA_FACTURA'
    end
    object QDATEFACTURANR_POZ: TIntegerField
      FieldName = 'NR_POZ'
      Origin = 'NR_POZ'
      ReadOnly = True
    end
    object QDATEFACTURAPRET_INTRARE: TFMTBCDField
      FieldName = 'PRET_INTRARE'
      Origin = 'PRET_INTRARE'
      ReadOnly = True
      Precision = 38
      Size = 2
    end
    object QDATEFACTURAPRET_TVA: TFMTBCDField
      FieldName = 'PRET_TVA'
      Origin = 'PRET_TVA'
      ReadOnly = True
      Precision = 38
      Size = 7
    end
    object QDATEFACTURAPRET_TOT: TFMTBCDField
      FieldName = 'PRET_TOT'
      Origin = 'PRET_TOT'
      ReadOnly = True
      Precision = 38
      Size = 2
    end
    object QDATEFACTURAEMITENT_ID: TFDAutoIncField
      FieldName = 'EMITENT_ID'
      Origin = 'EMITENT_ID'
      ReadOnly = True
    end
  end
  object DSQDATEFACTURA: TDataSource
    DataSet = QDATEFACTURA
    Left = 440
    Top = 344
  end
  object PFACTURA: TFDStoredProc
    Connection = BAZA
    StoredProcName = 'MAGAZIN.dbo.FACTURA'
    Left = 56
    Top = 312
    ParamData = <
      item
        Position = 1
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        ParamType = ptResult
      end
      item
        Position = 2
        Name = '@D'
        DataType = ftDate
        ParamType = ptInput
      end
      item
        Position = 3
        Name = '@N'
        DataType = ftString
        ParamType = ptInput
        Size = 20
      end
      item
        Position = 4
        Name = '@E'
        DataType = ftInteger
        ParamType = ptInput
      end>
  end
  object PCEK: TFDStoredProc
    Connection = BAZA
    StoredProcName = 'MAGAZIN.dbo.CEK'
    Left = 56
    Top = 408
    ParamData = <
      item
        Position = 1
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        ParamType = ptResult
        Value = 1
      end
      item
        Position = 2
        Name = '@OPER'
        DataType = ftInteger
        ParamType = ptInput
      end
      item
        Position = 3
        Name = '@CLIENT'
        DataType = ftInteger
        ParamType = ptInput
      end>
  end
  object QVANZARE: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      'SELECT D.VALOAREA AS PROCENT, *, PRET_INTRARE*STOCK1 AS SUMMA'
      
        ',CL.NUME+'#39' '#39'+CL.PRENUME AS CLIENT, O.NUME+'#39' '#39'+O.PRENUME AS OPERA' +
        'TOR'
      'FROM RECEPTIE R '
      #9#9#9#9#9#9' INNER JOIN PRODUSE P ON P.PRODUSE_ID=R.PRODUSE_ID'
      
        #9#9#9#9#9#9' INNER JOIN UNIT_MASURA UM ON UM.UNIT_MASURA_ID=R.UNIT_MAS' +
        'URA_ID'
      
        #9#9#9#9#9#9' INNER JOIN FACTURA_REC FK ON FK.FACTURA_REC_ID=R.FACTURA_' +
        'REC_ID'
      #9#9#9#9#9#9' INNER JOIN EMITENT E ON E.EMITENT_ID=FK.EMITENT_ID'
      #9#9#9#9#9#9' INNER JOIN VANZARE V ON V.RECEPTIE_ID=R.RECEPTIE_ID'
      #9#9#9#9#9#9' INNER JOIN CEC ON CEC.CEC_ID=V.CEC_ID'
      #9#9#9#9#9#9' INNER JOIN CLIENT CL ON CL.CLIENT_ID=CEC.CLIENT_ID'
      #9#9#9#9#9#9' INNER JOIN DISCOUNT D ON D.DISCOUNT_ID=CL.DISCOUNT_ID'
      
        #9#9#9#9#9#9' INNER JOIN FIRMA_OPERATOR F ON CEC.FIRMA_OPERATOR_ID=F.FI' +
        'RMA_OPERATOR_ID'
      
        '                         INNER JOIN OPERATOR O ON O.OPERATOR_ID=' +
        'F.OPERATOR_ID'
      'WHERE CEC.CEC_ID=:CEC_ID')
    Left = 312
    Top = 424
    ParamData = <
      item
        Name = 'CEC_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
    object QVANZAREPROCENT: TIntegerField
      FieldName = 'PROCENT'
      Origin = 'PROCENT'
    end
    object QVANZARERECEPTIE_ID: TFDAutoIncField
      FieldName = 'RECEPTIE_ID'
      Origin = 'RECEPTIE_ID'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = True
    end
    object QVANZAREPRODUSE_ID: TIntegerField
      FieldName = 'PRODUSE_ID'
      Origin = 'PRODUSE_ID'
    end
    object QVANZAREUNIT_MASURA_ID: TIntegerField
      FieldName = 'UNIT_MASURA_ID'
      Origin = 'UNIT_MASURA_ID'
    end
    object QVANZAREFACTURA_REC_ID: TIntegerField
      FieldName = 'FACTURA_REC_ID'
      Origin = 'FACTURA_REC_ID'
    end
    object QVANZAREFIRMA_OPERATOR_ID: TIntegerField
      FieldName = 'FIRMA_OPERATOR_ID'
      Origin = 'FIRMA_OPERATOR_ID'
    end
    object QVANZARESTOCK1: TIntegerField
      FieldName = 'STOCK1'
      Origin = 'STOCK1'
    end
    object QVANZARESTOCK2: TIntegerField
      FieldName = 'STOCK2'
      Origin = 'STOCK2'
    end
    object QVANZAREPRET_INTRARE: TBCDField
      FieldName = 'PRET_INTRARE'
      Origin = 'PRET_INTRARE'
      Precision = 7
      Size = 2
    end
    object QVANZAREPRET_VANZ: TBCDField
      FieldName = 'PRET_VANZ'
      Origin = 'PRET_VANZ'
      Precision = 7
      Size = 2
    end
    object QVANZARETVA: TIntegerField
      FieldName = 'TVA'
      Origin = 'TVA'
    end
    object QVANZAREACTIV: TBooleanField
      FieldName = 'ACTIV'
      Origin = 'ACTIV'
    end
    object QVANZAREPRODUSE_ID_1: TFDAutoIncField
      FieldName = 'PRODUSE_ID_1'
      Origin = 'PRODUSE_ID'
      ReadOnly = True
    end
    object QVANZAREDENUMIRE: TStringField
      FieldName = 'DENUMIRE'
      Origin = 'DENUMIRE'
      Size = 30
    end
    object QVANZARECOD_PRODUS: TStringField
      FieldName = 'COD_PRODUS'
      Origin = 'COD_PRODUS'
    end
    object QVANZAREUNIT_MASURA_ID_1: TFDAutoIncField
      FieldName = 'UNIT_MASURA_ID_1'
      Origin = 'UNIT_MASURA_ID'
      ReadOnly = True
    end
    object QVANZAREABREVIERE: TStringField
      FieldName = 'ABREVIERE'
      Origin = 'ABREVIERE'
      Size = 5
    end
    object QVANZARENUME: TStringField
      FieldName = 'NUME'
      Origin = 'NUME'
      Size = 10
    end
    object QVANZAREFACTURA_REC_ID_1: TFDAutoIncField
      FieldName = 'FACTURA_REC_ID_1'
      Origin = 'FACTURA_REC_ID'
      ReadOnly = True
    end
    object QVANZARENR_FACTURA: TStringField
      FieldName = 'NR_FACTURA'
      Origin = 'NR_FACTURA'
    end
    object QVANZAREDATA_FACTURA: TDateField
      FieldName = 'DATA_FACTURA'
      Origin = 'DATA_FACTURA'
    end
    object QVANZAREEMITENT_ID: TIntegerField
      FieldName = 'EMITENT_ID'
      Origin = 'EMITENT_ID'
    end
    object QVANZAREEMITENT: TStringField
      FieldName = 'EMITENT'
      Origin = 'EMITENT'
      Size = 100
    end
    object QVANZAREEMITENT_ID_1: TFDAutoIncField
      FieldName = 'EMITENT_ID_1'
      Origin = 'EMITENT_ID'
      ReadOnly = True
    end
    object QVANZAREDENUMIRE_1: TStringField
      FieldName = 'DENUMIRE_1'
      Origin = 'DENUMIRE'
      Size = 50
    end
    object QVANZAREIDNP: TStringField
      FieldName = 'IDNP'
      Origin = 'IDNP'
      Size = 15
    end
    object QVANZAREADRESA: TStringField
      FieldName = 'ADRESA'
      Origin = 'ADRESA'
      Size = 50
    end
    object QVANZAREVANZARE_ID: TFDAutoIncField
      FieldName = 'VANZARE_ID'
      Origin = 'VANZARE_ID'
      ReadOnly = True
    end
    object QVANZARECEC_ID: TIntegerField
      FieldName = 'CEC_ID'
      Origin = 'CEC_ID'
    end
    object QVANZARERECEPTIE_ID_1: TIntegerField
      FieldName = 'RECEPTIE_ID_1'
      Origin = 'RECEPTIE_ID'
    end
    object QVANZARECANTITATEA: TIntegerField
      FieldName = 'CANTITATEA'
      Origin = 'CANTITATEA'
    end
    object QVANZARESUMA: TBCDField
      FieldName = 'SUMA'
      Origin = 'SUMA'
      Precision = 7
      Size = 2
    end
    object QVANZARESUMA_DISC: TBCDField
      FieldName = 'SUMA_DISC'
      Origin = 'SUMA_DISC'
      Precision = 8
      Size = 3
    end
    object QVANZARESUMA_TOTAL: TBCDField
      FieldName = 'SUMA_TOTAL'
      Origin = 'SUMA_TOTAL'
      Precision = 7
      Size = 2
    end
    object QVANZARECEC_ID_1: TFDAutoIncField
      FieldName = 'CEC_ID_1'
      Origin = 'CEC_ID'
      ReadOnly = True
    end
    object QVANZARECLIENT_ID: TIntegerField
      FieldName = 'CLIENT_ID'
      Origin = 'CLIENT_ID'
    end
    object QVANZAREFIRMA_OPERATOR_ID_1: TIntegerField
      FieldName = 'FIRMA_OPERATOR_ID_1'
      Origin = 'FIRMA_OPERATOR_ID'
    end
    object QVANZARENR_CEC: TIntegerField
      FieldName = 'NR_CEC'
      Origin = 'NR_CEC'
    end
    object QVANZAREDATA_CEC: TSQLTimeStampField
      FieldName = 'DATA_CEC'
      Origin = 'DATA_CEC'
    end
    object QVANZARESUMA_CEC: TFloatField
      FieldName = 'SUMA_CEC'
      Origin = 'SUMA_CEC'
    end
    object QVANZARENR_POZ: TIntegerField
      FieldName = 'NR_POZ'
      Origin = 'NR_POZ'
    end
    object QVANZARECLIENT_ID_1: TFDAutoIncField
      FieldName = 'CLIENT_ID_1'
      Origin = 'CLIENT_ID'
      ReadOnly = True
    end
    object QVANZAREDISCOUNT_ID: TIntegerField
      FieldName = 'DISCOUNT_ID'
      Origin = 'DISCOUNT_ID'
    end
    object QVANZARENUME_1: TStringField
      FieldName = 'NUME_1'
      Origin = 'NUME'
      Size = 30
    end
    object QVANZAREPRENUME: TStringField
      FieldName = 'PRENUME'
      Origin = 'PRENUME'
      Size = 30
    end
    object QVANZAREDATA_NAST: TDateField
      FieldName = 'DATA_NAST'
      Origin = 'DATA_NAST'
    end
    object QVANZAREDATA_REG: TDateField
      FieldName = 'DATA_REG'
      Origin = 'DATA_REG'
    end
    object QVANZARECOD_CLIENT: TStringField
      FieldName = 'COD_CLIENT'
      Origin = 'COD_CLIENT'
      Size = 13
    end
    object QVANZAREDISCOUNT_ID_1: TFDAutoIncField
      FieldName = 'DISCOUNT_ID_1'
      Origin = 'DISCOUNT_ID'
      ReadOnly = True
    end
    object QVANZARENUME_2: TStringField
      FieldName = 'NUME_2'
      Origin = 'NUME'
    end
    object QVANZAREVALOAREA: TIntegerField
      FieldName = 'VALOAREA'
      Origin = 'VALOAREA'
    end
    object QVANZAREACTIV_1: TBooleanField
      FieldName = 'ACTIV_1'
      Origin = 'ACTIV'
    end
    object QVANZAREFIRMA_OPERATOR_ID_2: TFDAutoIncField
      FieldName = 'FIRMA_OPERATOR_ID_2'
      Origin = 'FIRMA_OPERATOR_ID'
      ReadOnly = True
    end
    object QVANZAREFIRMA_ID: TIntegerField
      FieldName = 'FIRMA_ID'
      Origin = 'FIRMA_ID'
    end
    object QVANZARETIP_ACCES: TStringField
      FieldName = 'TIP_ACCES'
      Origin = 'TIP_ACCES'
      Size = 10
    end
    object QVANZAREOPERATOR_ID: TIntegerField
      FieldName = 'OPERATOR_ID'
      Origin = 'OPERATOR_ID'
    end
    object QVANZAREOPERATOR_ID_1: TFDAutoIncField
      FieldName = 'OPERATOR_ID_1'
      Origin = 'OPERATOR_ID'
      ReadOnly = True
    end
    object QVANZARENUME_3: TStringField
      FieldName = 'NUME_3'
      Origin = 'NUME'
      Size = 30
    end
    object QVANZAREPRENUME_1: TStringField
      FieldName = 'PRENUME_1'
      Origin = 'PRENUME'
      Size = 30
    end
    object QVANZAREFUNCTIA: TStringField
      FieldName = 'FUNCTIA'
      Origin = 'FUNCTIA'
    end
    object QVANZAREUSERNAME: TStringField
      FieldName = 'USERNAME'
      Origin = 'USERNAME'
      Size = 10
    end
    object QVANZAREPASS: TStringField
      FieldName = 'PASS'
      Origin = 'PASS'
      Size = 10
    end
    object QVANZARECOD: TStringField
      FieldName = 'COD'
      Origin = 'COD'
      Size = 13
    end
    object QVANZARETIP_ACCES_1: TIntegerField
      FieldName = 'TIP_ACCES_1'
      Origin = 'TIP_ACCES'
    end
    object QVANZARESUMMA: TFMTBCDField
      FieldName = 'SUMMA'
      Origin = 'SUMMA'
      ReadOnly = True
      Precision = 18
      Size = 2
    end
    object QVANZARECLIENT: TStringField
      FieldName = 'CLIENT'
      Origin = 'CLIENT'
      ReadOnly = True
      Size = 61
    end
    object QVANZAREOPERATOR: TStringField
      FieldName = 'OPERATOR'
      Origin = 'OPERATOR'
      ReadOnly = True
      Size = 61
    end
  end
  object DSQVANZARE: TDataSource
    DataSet = QVANZARE
    Left = 432
    Top = 432
  end
  object QDateCec: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      
        'SELECT C.*,(SELECT SUM(SUMA) FROM VANZARE WHERE CEC_ID=C.CEC_ID)' +
        ' AS SUMA ,'
      
        '(SELECT SUM(SUMA_DISC) FROM VANZARE WHERE CEC_ID=C.CEC_ID) AS SU' +
        'MA_DISC,'
      
        'CL.NUME+'#39' '#39'+CL.PRENUME AS CLIENT,D.VALOAREA,OP.NUME+'#39' '#39'+OP.PRENU' +
        'ME AS OPERATOR'
      'FROM CEC C INNER JOIN CLIENT CL ON C.CLIENT_ID=CL.CLIENT_ID'
      '           INNER JOIN DISCOUNT D ON D.DISCOUNT_ID=CL.DISCOUNT_ID'
      
        #9#9'   INNER JOIN FIRMA_OPERATOR FO ON FO.FIRMA_OPERATOR_ID=C.FIRM' +
        'A_OPERATOR_ID'
      #9#9'   INNER JOIN OPERATOR OP ON OP.OPERATOR_ID=FO.OPERATOR_ID'
      'WHERE NR_CEC>0 AND CAST(DATA_CEC AS DATE) BETWEEN :D1 AND :D2')
    Left = 312
    Top = 504
    ParamData = <
      item
        Name = 'D1'
        DataType = ftDate
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'D2'
        DataType = ftDate
        ParamType = ptInput
        Value = Null
      end>
  end
  object DSDateCec: TDataSource
    DataSet = QDateCec
    Left = 432
    Top = 512
  end
end
