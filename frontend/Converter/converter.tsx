import axios from "axios";
import React, { useEffect, useRef, useState, type KeyboardEvent } from "react";

type url = {
  url: string;
};

type shortUrl = {
  shortUrl: string;
};

const Coverter: React.FC = () => {
  const [url, setUrl] = useState("");
  const printUrl = (url: string) => {
    console.log(url);
  };
  return (
    <div style={{
        display: 'flex',
        flexDirection: 'row',
        justifyContent: 'center',
        alignItems: 'center',
        minHeight: '100vh'
    }}>
      <textarea
        value={url}
        onChange={(e) => setUrl(e.target.value)}
        placeholder="Type your url"
        style={{ width: '600px', height: '20px', marginRight: '12px' }}
      />
      <button onClick={() => printUrl(url)} 
        style={
            {width: '70px', height: '30px', fontSize: '14px', paddingTop: '6px', paddingLeft:'13px'}
        }>Shorten
            
      </button>
    </div>
  );
};

export default Coverter;
